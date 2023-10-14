import subprocess
import os
import time
from pathlib import Path
from collections import defaultdict
import shutil

import toml


def ida_decompile(binary_path, functions=None, symboless=False, thirty_two_bit=False):
    max_wait = 50
    binary_path = Path(binary_path).absolute()
    bin_name = binary_path.with_suffix("").name
    ida_path = os.getenv("IDA_PATH") or 'idat64'
    if thirty_two_bit:
        ida_path = ida_path.replace("idat64","idat")

    cmd = f'{ida_path} -A -c -Ohexrays:ida_{bin_name}:ALL -S"{__file__}" {binary_path}'
    subprocess.run([cmd], timeout=300, shell=True)
    start_wait = time.time()
    while f'ida_{bin_name}.c' not in os.listdir("."):
        if time.time() - start_wait > max_wait:
            return None

        time.sleep(5)

    # delete intermediate ida files
    try:
        os.unlink(f"{binary_path.name}.i64")
    except Exception:
        pass

    new_path = Path(f"ida_{bin_name}.c").absolute()
    _clean_ida_file(new_path)

    # try to move linemaps if they were created
    try:
        shutil.move(binary_path.with_suffix(".ida.linemaps"), new_path.with_suffix(".linemaps"))
    except Exception:
        pass

    #with open(binary_path.with_suffix(".ida.maps"), "r") as fp:
    #    bin_func_line_maps = toml.load(fp)
    ## convert keys to int and values to set
    #for func in bin_func_line_maps:
    #    for linenum in list(bin_func_line_maps[func]):
    #        bin_func_line_maps[func][int(linenum)] = set(bin_func_line_maps[func][linenum])
    #        del bin_func_line_maps[func][linenum]

    return new_path


def _clean_ida_file(file_path: Path):
    with open(file_path, "r") as fp:
        dec_data = fp.read()

    # TODO: if we ever do more than x64, this needs to be updated!
    replacement_map = {
        "__int8": "char",
        "__int16": "short",
        "__int32": "int",
        "__int64": "long",
        "__fastcall": "",
        "__noreturn": "",
        "__cdecl": "",
        "::": "_",
    }

    for k, v in replacement_map.items():
        dec_data = dec_data.replace(k, v)

    with open(file_path, "w") as fp:
        fp.write(dec_data)


if __name__ == "__main__":
    # THIS CODE IS ONLY RUN INSIDE IDA
    import idaapi
    import idautils
    import idc
    import re

    from collections import defaultdict, Counter
    
    # TODO: make this configurable outside
    symboless = False

    def collect_call_counts():
        callees = defaultdict(list)
        # loop through all functions
        for function_ea in idautils.Functions():
            f_name = str(idc.get_func_name(function_ea)) if not symboless else hex(function_ea)
            # For each of the incoming references
            for ref_ea in idautils.CodeRefsTo(function_ea, 0):
                # Get the name of the referring function
                caller_name = str(idc.get_func_name(ref_ea)) if not symboless else hex(ref_ea) 
                # Add the current function to the list of functions
                # called by the referring function
                callees[caller_name].append(f_name)

        counts = {
            k: dict(Counter(v)) for k,v in callees.items()
        }
        return counts

    def collect_countable_metrics(cfunc):
        func_text = str(cfunc)
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
        return counts

    def dec_line_map(cfunc):
        linenum_to_addr = defaultdict(set)

        # always add the start as line 1
        linenum_to_addr[1].add(cfunc.entry_ea)

        # find all lines 2 - N
        for addr, lines in cfunc.get_eamap().items():
            for line in lines:
                y_holder = idaapi.int_pointer()
                if not cfunc.find_item_coords(line, None, y_holder):
                    continue

                linenum = y_holder.value()
                linenum_to_addr[linenum].add(addr)

        linenum_to_addr = {str(k): v for k, v in linenum_to_addr.items()}
        return linenum_to_addr

    idc.auto_wait()
    func_line_maps = {}
    func_metric_counts = {}
    for func in idautils.Functions():
        starttime = time.time()
        try:
            cfunc = idaapi.decompile(func)
        except Exception:
            continue
        
        if symboless:
            func_name = hex(func) 
        else:
            func_name = str(idaapi.get_func_name(func))


        try:
            func_metric_counts[func_name] = collect_countable_metrics(cfunc)
        except Exception:
            continue

        try:
            func_metric_counts[func_name]["dec_time"] = time.time() - starttime
            func_line_maps[func_name] = dec_line_map(cfunc)
        except:
            continue

    call_counts = collect_call_counts()
    for _func_name in func_metric_counts:
        if _func_name in call_counts:
            counts = call_counts[_func_name]
            if not counts:
                counts = {"__empty__": 0}

            func_metric_counts[_func_name].update({"func_calls": counts})
        else:
            func_metric_counts[_func_name].update({"func_calls": {"__empty__": 0}})

    path = Path(idaapi.get_input_file_path())
    with open(path.with_suffix(".ida.linemaps"), "w") as fp:
        toml.dump(func_line_maps, fp)

    binary_name = path.with_suffix("").name
    parent = path.parent
    with open(parent.joinpath(Path(f"ida_{binary_name}.toml")), "w") as fp:
        toml.dump(func_metric_counts, fp)
