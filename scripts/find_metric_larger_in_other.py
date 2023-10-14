#!/usr/bin/env python3
import argparse
import os
from pathlib import Path
from multiprocessing import Pool
from subprocess import check_output, run

import tqdm
import toml

from sailreval.utils import load_tomls_by_bin_name

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Helps run analysis routines I run a lot!")

    parser.add_argument(
        'tomls_dir_path', help="Path to a sailr_measured directory containing target tomls", nargs="+"
    )
    parser.add_argument(
        '-metric', help="Metric to do comparison on", default="gotos"
    )
    parser.add_argument(
        '--old-dec', help="Path to a sailr_measured directory containing target tomls", default='angr_phoenix'
    )
    parser.add_argument(
        '--new-dec', help="Path to a sailr_measured directory containing target tomls", default='ida'
    )
    parser.add_argument(
        '--print-dec', help="Prints the decompilation after running", action="store_true"
    )
    parser.add_argument(
        '--diff', help="difference level", type=int, default=0
    )
    parser.add_argument(
        '--old-metric-is-zero', help="difference level", action="store_true", default=False
    )




    args = parser.parse_args()
    multi_proj = False
    if len(args.tomls_dir_path) == 2:
        data = list()
        names = list()
        for toml_dir_path in args.tomls_dir_path:
            path = Path(toml_dir_path).expanduser().absolute()
            names.append(f"{path.parent.parent.parent.name}/{path.parent.name}") 
            data.append(load_tomls_by_bin_name(path))
        new_data = data[1]
        data = data[0]
        multi_proj = True
        old_name = names[0]
        new_name = names[1]
    else:
        path = Path(args.tomls_dir_path[0]).expanduser().absolute()
        data = load_tomls_by_bin_name(path)

    
    def _format_number(num):
        if isinstance(num, str):
            return int(float(num))

        return num

    #
    # do it!
    #

    hits = {}
    for bin_name, bin_data in data.items():
        old_metric = bin_data.get(args.old_dec, {}).get(args.metric, None)
        if multi_proj:
            new_metric = new_data.get(bin_name, {}).get(args.new_dec, {}).get(args.metric, None)
        else:
            new_metric = bin_data.get(args.new_dec, {}).get(args.metric, None)
        
        if new_metric is None or old_metric is None:
            continue
    
        for func, old_score in old_metric.items():
            if func not in new_metric:
                continue

            old_score = _format_number(old_score)
            new_score = _format_number(new_metric[func])
            if (args.old_metric_is_zero and old_score == 0) or not args.old_metric_is_zero:
                if new_score > old_score and new_score - old_score >= args.diff:
                    diff = new_score - old_score
                    if multi_proj:
                        out_str = f"{bin_name}.{func}: {new_name}:{args.new_dec}:{new_score} > {old_name}:{args.old_dec}:{old_score}"
                    else:
                        out_str = f"{bin_name}.{func}: {args.new_dec}:{new_score} > {args.old_dec}:{old_score}"

                    hits[out_str] = diff

    for hit, diff in sorted(hits.items(), key=lambda x: x[1], reverse=True):
        print(hit)
