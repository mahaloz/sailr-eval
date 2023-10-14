import os
import toml
from pathlib import Path

from collections import Counter
from sailreval import ALL_DECOMPILERS, ALL_METRICS

def remove_inconsistant_functions(goto_counter, ged_counter, binary, total_dict, decompilers):
    goto_remove_list = []
    ged_remove_list = []
    valid_decompilers = [x for x in decompilers if binary in total_dict[x]]
    for k, v in goto_counter.items():
        if v != len(valid_decompilers):
            goto_remove_list.append(k)

    for k, v in ged_counter.items():
        if v != len(valid_decompilers):
            ged_remove_list.append(k)
    
    for d in valid_decompilers:
        for func in goto_remove_list:
            try:
                total_dict[d][binary]['gotos'].pop(func)
            except KeyError:
                pass
        for func in ged_remove_list:
            try:
                total_dict[d][binary]['ged'].pop(func)
            except KeyError:
                pass
    return total_dict

def create_summary(total_dict, decompilers):
    summary = {d: dict() for d in decompilers}
    for d, binaries in total_dict.items():
        goto_funcs = 0
        for bin_name, metrics in binaries.items():
            for metric, values in metrics.items():
                if metric == "ged":
                    if metric + "_total" not in summary[d]:
                        summary[d][metric + "_total"] = 0.0
                        summary[d][metric] = dict()
                        summary[d]["total_analyzed_functions_ged"] = 0
                    ged_total = sum([float(x) for x in values.values()])
                    summary[d][metric + "_total"] += ged_total
                    summary[d][metric][bin_name] = ged_total
                    summary[d]["total_analyzed_functions_ged"] += len(values.keys())

                elif metric == "bools":
                    if metric not in summary[d]:
                        summary[d][metric] = {"or": 0, "and": 0}
                    if bin_name not in summary[d][metric]:
                        summary[d][metric][bin_name] = {"or": 0, "and": 0}
                    for func, func_vals in values.items():
                        summary[d][metric]["or"] += func_vals["or"]
                        summary[d][metric]["and"] += func_vals["and"]
                        summary[d][metric][bin_name]["or"] += func_vals["or"]
                        summary[d][metric][bin_name]["and"] += func_vals["and"]

                elif metric in ALL_METRICS:
                    if metric not in summary[d]:
                        summary[d][metric] = 0
                        if metric == "gotos":
                            summary[d][f"total_analyzed_functions_gotos"] = 0
                    if metric == "gotos":
                        goto_funcs += len([k for k, v in values.items() if v > 0])
                        summary[d]["total_analyzed_functions_gotos"] += len(values.keys())
                    
                    summary[d][metric] += sum(values.values())
        summary[d]["gotos_funcs"] = goto_funcs
    return summary

def analyze_dups(total_dict, decompilers):
    bins = list(total_dict["source"].keys())
    decompilers = [x for x in decompilers if x != "source"]
    summary = {d: {"func_calls": {b: None}} for d in decompilers for b in bins}
    for b in bins:
        if "func_calls" not in total_dict["source"][b]:
            continue
        base = {k: Counter(v) for k, v in total_dict["source"][b].pop("func_calls").items()}
        for d in decompilers:
            if b not in total_dict[d]:
                continue
            other = {k: (Counter(v) - base[k]).total() for k, v in total_dict[d][b]["func_calls"].items() if k in base}
            summary[d]["func_calls"][b] = Counter(other).total()
            total_dict[d][b]["func_calls"] = other
    return summary, total_dict


def merged_results_from_directory(dirname, decs=None, remove_errors=True):
    if decs is None:
        decs = ALL_DECOMPILERS
    if "source" not in decs:
        decs.append("source")
    dirname = Path(dirname).absolute()
    targets = [t.absolute() for t in dirname.rglob("*.toml")]
    total = {d: dict() for d in decs}
    for target in targets:
        with open(target, "r") as t:
            data = toml.load(t)
            goto_counter = Counter()
            ged_counter = Counter()
            valid_decompilers = [d for d in decs if d in data]
            for d in valid_decompilers:
                total[d][data['binary']] = data[d]
                if 'gotos' in data[d]:
                    goto_counter.update(data[d]['gotos'].keys())
                if 'ged' in data[d]:
                    ged_counter.update(data[d]['ged'].keys())

            if remove_errors:
                total = remove_inconsistant_functions(goto_counter, ged_counter, data['binary'], total, decs)
    
    dup_summary, total = analyze_dups(total, decs)
    summary = create_summary(total, decs)
    for d in [x for x in decs if x != "source"]:
        try:
            summary[d]["func_calls"] = dup_summary[d]["func_calls"]
        except KeyError:
            continue

    total["summary"] = summary
    return total
