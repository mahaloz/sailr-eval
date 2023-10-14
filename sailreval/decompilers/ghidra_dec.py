import json
import os
import subprocess
import shutil
from pathlib import Path
import logging
import hashlib

import toml

l = logging.getLogger(__name__)

DUMP_CODE = """
from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.pcode import PcodeOp
from ghidra.app.decompiler import PrettyPrinter

import traceback
import re
import os
import json
import time
from collections import defaultdict, Counter


def collect_call_counts(decomp_func):
    called_functions = list()
    if decomp_func is not None:
        # Iterate over the PcodeOp objects in the decompiled code
        for op in decomp_func.getHighFunction().pcodeOps:
            if op.getOpcode() == PcodeOp.CALL:
                called_func_addr = op.inputs[0].getAddress()
                called_func = currentProgram.getFunctionManager().getFunctionContaining(called_func_addr)
                if called_func is not None:
                    called_functions.append(called_func.name)
    
    out = dict(Counter(called_functions))
    if not out:
        out = {"__empty__": 0}
    
    return out

def collect_countable_metrics(func_text):
    gotos = re.findall("goto [a-zA-Z0-9_]*;", func_text, re.DOTALL)
    goto_cnt = len(gotos)
    and_cnt = func_text.count("&&")
    or_cnt = func_text.count("||")

    counts = {
        "loc": len(func_text.split("\\n")),
        "gotos": goto_cnt,
        "bools": {
            "ands": and_cnt,
            "ors": or_cnt
        }
    }
    return counts

def collect_line_maps(decomp_func):
    linenum_to_addr = defaultdict(set)
    function = decomp_func.function
    linenum_to_addr[1].add(function.entryPoint.offset)
    pp = PrettyPrinter(function, decomp_func.getCCodeMarkup())
    for line in pp.getLines():
        ln = line.getLineNumber()
        for i in range(line.getNumTokens()):
            min_addr = line.getToken(i).getMinAddress()
            if min_addr is None:
                continue

            linenum_to_addr[ln].add(min_addr.offset)
            max_addr = line.getToken(i).getMaxAddress()
            if max_addr is not None:
                linenum_to_addr[ln].add(max_addr.offset)

    list_linenum_to_addr = {
        str(k): list(v) for k,v in dict(linenum_to_addr).items()
    }

    return list_linenum_to_addr


prog_name = currentProgram.name
if "." in prog_name:
    prog_name = prog_name.split(".")[0]
prog_parent_path = os.path.dirname(currentProgram.executablePath)
if prog_parent_path == "/":
    prog_parent_path = "./"
c_output_path = prog_parent_path + "/ghidra_" + prog_name + ".c"
metric_output_path = prog_parent_path + "/ghidra_" + prog_name + ".toml"
linemaps_output_path = prog_parent_path + "/ghidra_" + prog_name + ".linemaps"

output_text = ""
counted_metrics = {}
linemaps = {}
for f in currentProgram.getFunctionManager().getFunctions(True):
    starttime = time.time()
    try:
        di = DecompInterface()
        di.openProgram(currentProgram)
        dec_func = di.decompileFunction(f, 0, None)
        func_text = dec_func.getDecompiledFunction().getC()
    except:
        continue

    output_text += func_text
    output_text += "\\n"
    func_name = str(f.name) + "__SAILR__" + hex(f.entryPoint.offset)[:-1]

    try:
        counted_metrics[func_name] = collect_countable_metrics(func_text)
    except Exception as e:
        continue

    try:
        counted_metrics[func_name].update({"func_calls": collect_call_counts(dec_func)})
    except Exception as e:
        continue

    try:
        counted_metrics[func_name]["dec_time"] = time.time() - starttime
        linemaps[func_name] = collect_line_maps(dec_func)
    except Exception as e:
        continue

with open(c_output_path, "w") as fp:
    fp.write(output_text)

with open(metric_output_path, "w") as fp:
    json.dump(counted_metrics, fp)

with open(linemaps_output_path, "w") as fp:
    json.dump(linemaps, fp)
"""


def _generate_scripts(write_path='/tmp/dump.py', binary_name=None):
    post_code_path = Path(write_path).absolute()
    with open(post_code_path, "w") as fp:
        fp.write(DUMP_CODE)

    return post_code_path


def _convert_json_to_toml_and_fix_name(josn_path: Path, symboless=False):
    with open(josn_path, "r") as fp:
        json_data = json.load(fp)

    new_data = {}
    for func_name, data in json_data.items():
        sym_nam, addr = func_name.split("__SAILR__")
        if symboless:
            new_data[addr] = data
        else:
            new_data[sym_nam] = data

    # XXX: the name will already end in .toml
    with open(josn_path, "w") as fp:
        toml.dump(new_data, fp)

def path_hash_str(path: Path):
    return hashlib.md5(bytes(path)).hexdigest() 

def ghidra_decompile(binary_path, functions=None, symboless=False):
    """
    Taken from mdec with modifications
    """
    binary_path = Path(binary_path).absolute()

    bin_name = binary_path.with_suffix("").name
    output_dec_filename = f"ghidra_{bin_name}.c"
    metric_output_filename = f"ghidra_{bin_name}.toml"
    linemaps_output_filename = f"ghidra_{bin_name}.linemaps"
    post_code_path = _generate_scripts(write_path=f"/tmp/ghidra_{path_hash_str(binary_path)}_{bin_name}.py", binary_name=bin_name)

    # something like: /ghidra/support/analyzeHeadless
    ghidra_path = os.getenv("GHIDRA_PATH") or 'analyzeHeadless'
    original_cwd = os.getcwd()
    output_file = None
    try:
        dir_path = os.path.dirname(binary_path)
        os.chdir(dir_path)
        subprocess.run(
            [f'{ghidra_path}', '.', f'temp_project_{bin_name}',
             '-import', os.path.basename(binary_path),
             '-postScript', f'{post_code_path}']
        )

        shutil.move(output_dec_filename, f"{original_cwd}/{output_dec_filename}")
        output_file = f"{original_cwd}/{output_dec_filename}"

        _convert_json_to_toml_and_fix_name(metric_output_filename, symboless=symboless)
        _convert_json_to_toml_and_fix_name(linemaps_output_filename, symboless=symboless)
        shutil.move(metric_output_filename, f"{original_cwd}/{metric_output_filename}")
        shutil.move(linemaps_output_filename, f"{original_cwd}/{linemaps_output_filename}")
        os.unlink(f"./temp_project_{bin_name}.gpr")
        shutil.rmtree(f"./temp_project_{bin_name}.rep")
    except Exception as e:
        l.critical(f"Ghidra decompilation exeception: {e}")
    finally:
        os.chdir(original_cwd)
        os.unlink(post_code_path)

    return output_file
