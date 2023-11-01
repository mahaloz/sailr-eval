import logging
from pathlib import Path
import re
from subprocess import run
from collections import defaultdict

from elftools.elf.elffile import ELFFile
from elftools.dwarf.descriptions import set_global_machine_arch
import toml

l = logging.getLogger(__name__)

#
# DWARF Parsing & Dumping
#

def _lineprog(dwarfinfo, CU):
    line_program = dwarfinfo.line_program_for_CU(CU)
    if not line_program:
        return []
    return line_program.get_entries()


def _start_address(dwarfinfo):
    '''
    starting address to line mapping as in `.debug_line`
    same as readelf's output
    return: addr_to_line and rebased_addr_to_line
    '''
    addr_line = defaultdict(set)
    rebased_addr = dict()

    for CU in dwarfinfo.iter_CUs():
        lpe = _lineprog(dwarfinfo, CU)
        for lp in lpe:
            if not lp.state:
                continue
            # addr: 0x1285 rebased: 0x401285
            # starting address for the line
            addr = lp.state.address
            rebased_addr[(int(0x400000) + addr)] = addr
            line = lp.state.line
            if addr in addr_line:
                addr_line[addr].add(line)
            else:
                addr_line[addr] = {line}

    return addr_line, rebased_addr


def _all_address(dwarfinfo, binpath):
    '''
    starting address to line mapping as in `.debug_line` (readelf's output)
    + possible address in for same line
    '''

    # all instruction address per angr
    all_addrs = _angr_collect_address(binpath)
    # get starting address
    total_addr_line, rebased_addr = _start_address(dwarfinfo)
    # unknown addresses
    # case1: one source line can have multiple instruction addresses which are not shown in `.debug_line`
    # case2: false positive (hopefully not many fp)
    unkn_addr_line = set(all_addrs) - set(rebased_addr)

    for raddr in unkn_addr_line:
        addr = (raddr - int(0x400000))
        for CU in dwarfinfo.iter_CUs():
            lpe = _lineprog(dwarfinfo, CU)
            prev = None
            for lp in lpe:
                if not lp.state:
                    continue
                # prev instruction addr <= current instruction addr < instruction address for next source line
                if prev and prev.address <= addr < lp.state.address:
                    line = prev.line
                    if addr in total_addr_line:
                        total_addr_line[addr].add(line)
                    else:
                        total_addr_line[addr] = {line}
                if lp.state.end_sequence:
                    prev = None
                else:
                    prev = lp.state

    return total_addr_line


def _angr_collect_address(binpath):
    '''
    iterate over all blocks and collect instruction addrs
    '''
    import angr

    all_addrs = []
    project = angr.Project(binpath, auto_load_libs=False, load_debug_info=True)
    cfg = project.analyses.CFG(data_references=True, normalize=True)
    for func in cfg.functions.values():
        if func.is_plt or func.is_simprocedure:
            continue
        if not func.get_block_size(func.addr):
            continue
        for block in func.blocks:
            all_addrs.extend(block.instruction_addrs)

    return all_addrs


def _load_dwarf_info(binpath):
    with open(binpath, 'rb') as f:
        elffile = ELFFile(f)
        if not elffile.has_dwarf_info():
            print("no DWARF")
            return
        set_global_machine_arch(elffile.get_machine_arch())
        dwarfinfo = elffile.get_dwarf_info()
        return dwarfinfo


def gen_dwarf_addr_to_line_map(binary_path: Path, full_search=True):
    binary_path = Path(binary_path).absolute()
    dwarf_info = _load_dwarf_info(binary_path)

    if not full_search:
        total_addr_line, rebased_addr = _start_address(dwarf_info)
        return total_addr_line

    # XXX: uses angr to get all addresses (slow)
    return _all_address(dwarf_info, binary_path)


def dump_dwarf_addr_to_line_map(binary_path: Path, full_search=False):
    addr_to_line = gen_dwarf_addr_to_line_map(binary_path, full_search=full_search)
    output = {
        str(k): v for k, v in addr_to_line.items()
    }

    output_path = binary_path.with_suffix(".dwarf.linemaps")
    with open(output_path, "w") as fp:
        toml.dump(output, fp)

    return output_path

#
# PE Debug Info (PDB) Parsing & Dumping
#


ADDR_LN_MAP_RE = re.compile(r"([0-9]{1,6}|NSI) ([0-9A-F]{8})")
FILE_RE = re.compile(r"([A-Z]:.*\.c)")
MOD_STARTS_RE = re.compile(r"Mod [0-9]{4} \| ")


def _run_pdbutil(filepath: Path):
    text = run(f"llvm-pdbutil dump -l {filepath}".split(" "), capture_output=True).stdout.decode()
    return text


def _extract_line_to_addr_map_for_pdb(filepath: Path):
    filepath = Path(filepath)
    text = _run_pdbutil(filepath)
    start_poss = [
        m.end() for m in MOD_STARTS_RE.finditer(text)
    ]

    end_pos_to_file = {}
    for m in FILE_RE.finditer(text):
        pos = m.start()
        filename = m.group(0)
        for i, start_pos in enumerate(start_poss):
            if i+1 == len(start_poss) and pos >= start_pos:
                end_pos_to_file[start_pos] = filename
                break
            elif pos >= start_pos and pos < start_poss[i+1]:
                end_pos_to_file[start_pos] = filename
                break


    bad_cnt = 0
    for start_pos in start_poss:
        if start_pos not in end_pos_to_file:
            end_pos_to_file[start_pos] = f"ERROR_{bad_cnt}"
            bad_cnt += 1

    end_positions = list(end_pos_to_file.keys())
    # [(start_of_mod, end_of_mod)]
    ranges = []
    for i, end_pos in enumerate(end_positions):
        if i+1 >= len(end_positions):
            r = (end_pos, None)
        else:
            r = (end_pos, end_positions[i+1] - 1)

        ranges.append(r)

    def _find_correct_file(pos):
        for r in ranges:
            start, end = r
            if pos > start and (end is None or pos < end):
                return end_pos_to_file[start]

    mapping = {v: defaultdict(set) for v in end_pos_to_file.values()}
    last_line_number = None
    for m in ADDR_LN_MAP_RE.finditer(text):
        pos = m.start()
        line_number = m.group(1)
        if line_number == "NSI":
            line_number = last_line_number
        else:
            line_number = int(line_number, 10)
            last_line_number = line_number

        addr = int(m.group(2), 16)

        win_filename =  _find_correct_file(pos)
        mapping[win_filename][line_number].add(addr)
    
    dict_mapping = {}
    for win_filename, v in mapping.items():
        if win_filename.startswith("ERROR"):
            continue

        # XXX: a hack for working on non Windows systems
        filename = win_filename.split("\\")[-1]
        if not filename.endswith(".c"):
            l.critical(f"We likely failed to parse name of {win_filename} you should check it...")
        

        dict_mapping[filename] = v
    
    return dict_mapping


def gen_pdb_addr_to_line_map(binary_path: Path):
    source_name = binary_path.with_suffix(".c").name
    line_to_addr_by_src = _extract_line_to_addr_map_for_pdb(binary_path)
    for src, line_to_addr_map in line_to_addr_by_src.items():
        if src == source_name:
            return line_to_addr_map
    else:
        l.critical(f"Failed to find the right source file mappings for {binary_path}")
        return {}


def dump_pdb_addr_to_line_map(binary_path: Path):
    addr_to_line = gen_pdb_addr_to_line_map(binary_path)
    output = {
        str(k): list(v) for k, v in addr_to_line.items()
    }

    output_path = binary_path.with_suffix(".dwarf.linemaps")
    with open(output_path, "w") as fp:
        toml.dump(output, fp)

    return output_path


#
# Extras
#

def read_line_maps(maps_path: Path, key_is_func=True, value_is_set_type=True):
    with open(maps_path, "r") as fp:
        line_maps = toml.load(fp)

    # convert keys to int and values to set
    if key_is_func:
        for func in line_maps:
            for linenum in list(line_maps[func]):
                if value_is_set_type:
                    line_maps[func][int(linenum)] = set(line_maps[func][linenum])
                else:
                    line_maps[func][int(linenum)] = line_maps[func][linenum]
                del line_maps[func][linenum]
    else:
        for addr in list(line_maps.keys()):
            line_maps[int(addr)] = set(line_maps[addr])
            del line_maps[addr]

    return line_maps
