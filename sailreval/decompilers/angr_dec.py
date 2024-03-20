import signal
from collections import defaultdict
from typing import List
from pathlib import Path
import logging
import hashlib
import re
import time

import toml

_DEBUG = False
l = logging.getLogger(__name__)


class timeout:
    def __init__(self, seconds=1, error_message='Timeout'):
        self.seconds = seconds
        self.error_message = error_message

    def handle_timeout(self, signum, frame):
        raise TimeoutError(self.error_message)

    def __enter__(self):
        signal.signal(signal.SIGALRM, self.handle_timeout)
        signal.alarm(self.seconds)

    def __exit__(self, type_, value, traceback):
        signal.alarm(0)


def _get_angr_dec_options(param_string):
    import angr
    opt_candidates = [
        o for o in angr.analyses.decompiler.decompilation_options.options
        if o.param == param_string
    ]

    if not opt_candidates:
        return None

    return opt_candidates[0]


def angr_comb_decompile(binary_path, functions=None, print_dec=False, **kwargs):
    return angr_decompile(binary_path, functions=functions, print_dec=print_dec, structurer="combing", use_sailr=False, name="angr_comb", improved_restruct=False, **kwargs)


def angr_improved_phoenix_decompile(binary_path, functions=None, print_dec=False, **kwargs):
    return angr_decompile(binary_path, functions=functions, print_dec=print_dec, structurer="phoenix", use_sailr=False, name="angr_improved_phoenix", improved_restruct=True, **kwargs)


def angr_phoenix_decompile(binary_path, functions=None, print_dec=False, **kwargs):
    return angr_decompile(binary_path, functions=functions, print_dec=print_dec, structurer="phoenix", use_sailr=False, name="angr_phoenix", improved_restruct=False, **kwargs)


def angr_dream_decompile(binary_path, functions=None, print_dec=False, **kwargs):
    return angr_decompile(binary_path, functions=functions, print_dec=print_dec, structurer="dream", use_sailr=False, name="angr_dream", improved_restruct=False, **kwargs)


def angr_decompile(
        binary_path,
        functions=None,
        print_dec=False,
        structurer="phoenix",
        use_sailr=True,
        func_dec_timeout=600,
        name="angr_sailr",
        improved_restruct=True,
        dump_line_maps=True,
        dump_early_metrics=True,
        symboless=False,
        disable_opts=[]
):
    #
    # Do dynamic imports
    #

    import angr
    # TODO: update then when everything is in master of angr
    from angr.analyses.decompiler.optimization_passes import LoweredSwitchSimplifier, ReturnDeduplicator
    from cle.backends.coff import Coff
    try:
        from angr.analyses.decompiler.optimization_passes import (
            DuplicationOptReverter, ConstPropOptReverter, CrossJumpReverter, FlipBooleanCmp, ITERegionConverter,
            ReturnDeduplicator, EagerReturnsSimplifier
        )
    except ImportError:
        DuplicationOptReverter = 1
        ConstPropOptReverter = 2
        CrossJumpReverter = 3
        FlipBooleanCmp = 4
        ITERegionConverter = 5
        ReturnDeduplicator = 6
        EagerReturnsSimplifier = 7

    #
    # real code
    #

    angr_name = name
    proj = angr.Project(binary_path, auto_load_libs=False)
    is_windows = proj.loader.main_object.os == "windows" or isinstance(proj.loader.main_object, Coff)
    cfg = proj.analyses.CFG(show_progressbar=False, normalize=True, data_references=True)
    try:
        proj.analyses.CompleteCallingConventions(cfg=cfg, recover_variables=True, analyze_callsites=True)
        cc_failed = False
    except Exception:
        cc_failed = True

    if cc_failed:
        l.warning(f"CallingConvention Analysis failed on {binary_path}. Trying again without variable recovery...")
        try:
            # try it again without variable recovery
            proj.analyses.CompleteCallingConventions(cfg=cfg, recover_variables=False)
            cc_failed = False
        except Exception:
            pass

    if cc_failed:
        l.critical(f"All attempts to run CallingConvention Analysis failed on {binary_path}.")

    all_optimization_passes = angr.analyses.decompiler.optimization_passes.get_default_optimization_passes("AMD64", "linux")

    # decide to use options in SAILR package
    opt_blacklist = [] if use_sailr else [
        DuplicationOptReverter, ConstPropOptReverter, CrossJumpReverter, EagerReturnsSimplifier,
        LoweredSwitchSimplifier, FlipBooleanCmp, ITERegionConverter, ReturnDeduplicator
    ]
    if is_windows and LoweredSwitchSimplifier not in opt_blacklist:
         opt_blacklist.append(LoweredSwitchSimplifier)

    if disable_opts:
        loaded_opts = [
            globals()[opt] for opt in disable_opts if opt in globals()
        ]
        for opt in loaded_opts:
            if opt not in opt_blacklist:
                opt_blacklist.append(opt) 

    if improved_restruct:
        # improves structuring gets boolean flipper
        if FlipBooleanCmp in opt_blacklist:
            opt_blacklist.remove(FlipBooleanCmp)

    all_optimization_passes = [
        p for p in all_optimization_passes
        if p not in opt_blacklist
    ]

    binary_path = Path(binary_path).absolute()
    bin_name = binary_path.with_suffix("").name
    output_path = binary_path.parent.joinpath(f"{angr_name}_{bin_name}.c").absolute()
    functions = functions or cfg.functions
    decompilation = ""

    # clean up function names
    for func in list(cfg.functions.values()):
        if "." in func.name:
            func.name = func.name[:func.name.index(".")]

    # decide to use options
    options = [
        (_get_angr_dec_options("structurer_cls"), structurer),
        (_get_angr_dec_options("comment_gotos"), False),
        (_get_angr_dec_options("braces_on_own_lines"), False),
        (_get_angr_dec_options("show_local_types"), False),
        (_get_angr_dec_options("show_externs"), False),
        (_get_angr_dec_options("show_casts"), False),
        (_get_angr_dec_options("improve_structurer"), improved_restruct),
        (_get_angr_dec_options("largest_successor_tree_outside_loop"), improved_restruct),
        (_get_angr_dec_options("simplify_switches"), use_sailr),
    ]
    # add extra option which may not be available based on commit version
    simplify_ifelse_opt = _get_angr_dec_options("simplify_ifelse")
    if simplify_ifelse_opt is not None:
        options.append((simplify_ifelse_opt, improved_restruct))

    linemaps = {}
    metrics = {}
    for func_idx, func_addr in enumerate(functions):
        try:
            f = cfg.functions[func_addr]
        except Exception:
            continue

        if f is None:
            continue

        if f.is_plt:
            continue

        starttime = time.time()
        exception_string = ""
        if _DEBUG:
            dec = proj.analyses.Decompiler(f, cfg=cfg, kb=cfg.kb, options=options, optimization_passes=all_optimization_passes)
        else:
            try:
                l.info(f"Decompiling {bin_name}.{f.name} now ({func_idx}/{len(functions)})...")
                with timeout(seconds=func_dec_timeout):
                    dec = proj.analyses.Decompiler(f, cfg=cfg, kb=cfg.kb, options=options, optimization_passes=all_optimization_passes)
            except Exception as e:
                l.critical(f"Failed to decompile {bin_name}.{f.name} because {e}")
                exception_string = str(e).replace("\n", " ")
                dec = None

        # exception forcefully crashed
        has_error = exception_string != ""

        #
        # do sanity checks on decompilation, skip checks if we already errored
        #

        # codegen failed in decompilation but did not crash, probably in structuring
        if not has_error and (dec is None or not dec.codegen or not dec.codegen.text):
            exception_string = "Decompilation had no code output (failed in Dec)"
            has_error = True

        # codegen created code, but it was empty (likely structuring error)
        if not has_error and ("{\n}" in dec.codegen.text):
            exception_string = "Decompilation outputted an empty function (failed in structuring)"
            has_error = True

        # codegen created corrupted code
        #if not has_error and ("[D]" in dec.codegen.text or "DIRTY" in dec.codegen.text):
        #    exception_string = "Decompilation outputted a dirty function (failed in lifting)"
        #    has_error = True

        if not has_error and (structurer in ["dream", "combing"] and "goto" in dec.codegen.text):
            exception_string = "Decompilation outputted a goto for Gotoless algorithm (failed in structuring)"
            has_error = True

        # skip errored decompilation
        if has_error:
            l.critical(f"Failed to decompile {bin_name}.{f.name} because {exception_string}")
            decompilation += f"// [error: {f.name} | {exception_string}]\n"
            continue

        # decompilation must be valid
        delta_time = time.time() - starttime
        decompilation += dec.codegen.text + "\n"
        func_name = f.name if not symboless else hex(f.addr)

        # dump metrics
        if dump_line_maps and not print_dec:
            linemaps[func_name] = generate_linemaps(dec, dec.codegen, base_addr=proj.loader.main_object.min_addr)
        if dump_early_metrics and not print_dec:
            metrics[func_name] = collect_countable_metrics(dec.codegen)
            metrics[func_name]["dec_time"] = delta_time

    if print_dec:
        print(decompilation)
        return decompilation

    with open(output_path, "w") as fp:
        fp.write(decompilation)

    #
    # metric and extras dumping
    #

    if dump_line_maps:
        final_linemaps = {k: dict(v) for k,v in linemaps.items()}
        dump_path = output_path.with_suffix(".linemaps")
        with open(dump_path, "w") as fp:
            toml.dump(final_linemaps, fp)
    if dump_early_metrics:
        dump_path = output_path.with_suffix(".toml")
        with open(dump_path, "w") as fp:
            toml.dump(metrics, fp)

    return output_path


def generate_linemaps(dec, codegen, base_addr=0x400000):
    import ailment
    from angr.analyses.decompiler.structured_codegen.c import CStructuredCodeWalker, CFunctionCall, CIfElse, CIfBreak

    if codegen is None:
        return
    
    base_addr = dec.project.loader.main_object.image_base_delta
    if hasattr(dec, "unoptimized_ail_graph"):
        nodes = dec.unoptimized_ail_graph.nodes
    else:
        l.critical(f"You are likely using an older version of angr that has no unoptimized_ail_graph."
                  f" Using clinic_graph instead, results will be less accurate...")
        nodes = dec.clinic.cc_graph.nodes

    # get the mapping of the original AIL graph
    mapping = defaultdict(set)
    ail_node_addr_map = {
        node.addr: node for node in nodes
    }
    for addr, ail_block in ail_node_addr_map.items():
        # get instructions of this block
        try:
            vex_block = dec.project.factory.block(addr)
        except Exception:
            continue

        ail_block_stmts = [stmt for stmt in ail_block.statements if not isinstance(stmt, ailment.statement.Label)]
        if not ail_block_stmts:
            continue

        next_ail_stmt_idx = 0
        for ins_addr in vex_block.instruction_addrs:
            next_ail_stmt_addr = ail_block_stmts[next_ail_stmt_idx].ins_addr
            mapping[next_ail_stmt_addr].add(ins_addr)
            if ins_addr == next_ail_stmt_addr:
                next_ail_stmt_idx += 1
            if next_ail_stmt_idx >= len(ail_block_stmts):
                break

    # node to addr map
    ailaddr_to_addr = defaultdict(set)
    for k, v in mapping.items():
        for v_ in v:
            ailaddr_to_addr[k - base_addr].add(v_ - base_addr)

    """
    ail_node_addr_map = {
        node.addr: node for node in dec.clinic.cc_graph
    }
    """

    codegen.show_externs = False
    codegen.regenerate_text()

    decompilation = codegen.text
    if not decompilation:
        return
    
    try:
        first_code_pos = codegen.map_pos_to_addr.items()[0][0]
    except Exception:
        return

    # map the position start to an address
    pos_addr_map = defaultdict(set)
    for start, pos_map in codegen.map_pos_to_addr.items():
        obj = pos_map.obj
        if not hasattr(obj, "tags"):
            continue

        # leads to mapping at the beginning of loops, so skip.
        # see kill.o binary for send_signals
        if isinstance(obj, CIfElse):
            continue

        ins_addr = obj.tags.get("ins_addr", None)
        if ins_addr:
            pos_addr_map[start].add(ins_addr - base_addr)

        """
        vex_block_addr = obj.tags.get("vex_block_addr", None)
        if vex_block_addr == 0x400b59:
            breakpoint()

        if ins_addr is None:
            pos_addr_map[start].add(vex_block_addr - base_addr)
            continue

        ail_block = ail_node_addr_map.get(vex_block_addr, None)
        if ail_block is None:
            continue

        # get instructions of this block
        vex_block = dec.project.factory.block(vex_block_addr)
        ail_block_stmts = [stmt for stmt in ail_block.statements if not isinstance(stmt, ailment.statement.Label)]
        if not ail_block_stmts:
            continue

        next_ail_stmt_idx = 0
        for ins_addr in vex_block.instruction_addrs:
            next_ail_stmt_addr = ail_block_stmts[next_ail_stmt_idx].ins_addr
            mapping[next_ail_stmt_addr].add(ins_addr)
            if ins_addr == next_ail_stmt_addr:
                next_ail_stmt_idx += 1
            if next_ail_stmt_idx >= len(ail_block_stmts):
                break
        """


    # find every line
    line_end_pos = [i for i, x in enumerate(decompilation) if x == "\n"]
    line_to_addr = defaultdict(set)
    last_pos = len(decompilation) - 1
    line_to_addr[str(1)].add(codegen.cfunc.addr - base_addr)
    for i, pos in enumerate(line_end_pos[:-1]):
        if pos == last_pos:
            break

        curr_end = line_end_pos[i+1] - 1
        # check if this is the variable decs and header
        if curr_end < first_code_pos:
            line_to_addr[str(i+2)].add(codegen.cfunc.addr - base_addr)
            continue

        # not header, real code
        for p_idx in range(pos+1, curr_end+1):
            if p_idx in pos_addr_map:
                # line_to_addr[str(i+1)].update(pos_addr_map[p_idx])
                for ail_ins_addr in pos_addr_map[p_idx]:
                    if ail_ins_addr in ailaddr_to_addr:
                        line_to_addr[str(i+2)].update(ailaddr_to_addr[ail_ins_addr])
                    else:
                        line_to_addr[str(i+2)].add(ail_ins_addr)

    return line_to_addr


def count_cmove_insns(func):
    """
    func must be an angr function. Counts the number of cmove instructions in the function.
    """
    cmove_cnt = 0
    for block in func.blocks:
        for insn in block.disassembly.insns:
            if "cmove" in insn.mnemonic:
                cmove_cnt += 1

    return cmove_cnt


def collect_countable_metrics(codegen):
    from angr.analyses.decompiler.structured_codegen.c import CStructuredCodeWalker, CFunctionCall, CIfElse, CIfBreak
    #
    # gotos & bools
    #
    func_text = codegen.text
    gotos = re.findall("goto [a-zA-Z0-9_]*;", func_text, re.DOTALL)
    goto_cnt = len(gotos)
    and_cnt = func_text.count("&&")
    or_cnt = func_text.count("||")

    counts = {
        "loc": len(func_text.split("\n")),
        "gotos": goto_cnt,
        "bools": {
            "ands": and_cnt,
            "ors": or_cnt
        }
    }

    #
    # function calls
    #
    func_call_counts = defaultdict(int)
    class FunctionCallCounter(CStructuredCodeWalker):
        @classmethod
        def handle_CFunctionCall(cls, obj: CFunctionCall):
            if obj and obj.callee_func is not None:
                func_call_counts[obj.callee_func.name] += 1
            return super().handle_CFunctionCall(obj)

    FunctionCallCounter.handle(codegen.cfunc)
    func_call_counts = dict(func_call_counts)
    if not func_call_counts:
        func_call_counts = {"__empty__": 0}
    counts['func_calls'] = func_call_counts

    return counts


def angr_disassemble(binary_path, functions=None):
    import angr

    proj = angr.Project(binary_path, auto_load_libs=False)
    cfg = proj.analyses.CFG(show_progressbar=False, normalize=True)
    proj.analyses.CompleteCallingConventions(
        recover_variables=True,
        cfg=cfg,
        analyze_callsites=True,
        kb=cfg.kb,
    )

    functions = functions or cfg.functions
    return {
        func_name: cfg.functions[func_name].graph for func_name in functions
    }


def get_all_funcs(binary_path):
    import angr

    proj = angr.Project(binary_path, auto_load_libs=False)
    if not hasattr(proj.loader.main_object, "symbols_by_name"):
        return []

    syms: List[str] = [
        name for name, sym in proj.loader.main_object.symbols_by_name.items()
        if sym.is_function and not sym.is_import
    ]
    #cfg = proj.analyses.CFG(show_progressbar=False, normalize=True)
    #proj.analyses.CompleteCallingConventions(
    #    recover_variables=True,
    #    cfg=cfg,
    #    analyze_callsites=True,
    #    kb=cfg.kb,
    #)

    final_syms = []
    for sym in syms:
        if ".const" in sym:
            sym = sym.split(".const")[0]

        final_syms.append(sym)

    return final_syms


def _insn_bytes_from_func(function):
    insn_bytes = bytes()

    for blk_addr in sorted(function.block_addrs):
        blk = function.get_block(blk_addr)
        insn_bytes += blk.bytes

    return insn_bytes


def hash_functions(binary_path):
    import angr

    function_hash_dic = {}

    proj = angr.Project(binary_path, auto_load_libs=False)
    cfg = proj.analyses.CFGFast()

    functions = [func for addr, func in cfg.kb.functions.items()]

    for function in functions:
        function_insn_bytes = _insn_bytes_from_func(function)
        sha512_hash = hashlib.sha512(function_insn_bytes).hexdigest()
        function_hash_dic[function.name] = sha512_hash

    return function_hash_dic
