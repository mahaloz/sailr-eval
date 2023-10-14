#!/usr/bin/env python3

import argparse
from pathlib import Path

from sailreval import SAILR_DECOMPILERS, ALL_DECOMPILERS
from sailreval.metrics.ged_to_source import compute_cfg_edit_distance, ged_upperbound_score
from sailreval.joern.cfg.utils import cfgs_from_source, correct_source_cfg_addrs, save_as_png


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Helps run analysis routines I run a lot!")

    parser.add_argument(
        'dec_dir_path', help="Path to a sailr_decompiled directory containing target binaries"
    )
    parser.add_argument(
        'basename', help="The basename of the files, like 'fmt' for 'fmt.o'"
    )
    parser.add_argument(
        '--decs', help="Decompilers to grab files for",
        default=[SAILR_DECOMPILERS.ANGR_SAILR],
        nargs="+", choices=ALL_DECOMPILERS,
    )
    parser.add_argument(
        '--func', type=str
    )
    parser.add_argument(
        '--save-png', help="Save a PNG of the CFG for source and decompilation", action="store_true", default=False
    )

    args = parser.parse_args()
    dec_dir_path = Path(args.dec_dir_path).expanduser().absolute()

    basename = args.basename
    function = args.func

    # extract the cfg from source
    source_filename = f"source_{basename}.c"
    source_filepath = dec_dir_path / source_filename
    binary_path = dec_dir_path / f"{basename}.o"
    linemaps_path = source_filepath.with_suffix(".linemaps")
    extracted_cfgs = cfgs_from_source(source_filepath)
    source_cfgs = correct_source_cfg_addrs(
        extracted_cfgs,
        linemaps_path,
    )
    if args.save_png:
        output_file = dec_dir_path / f"source_{basename}_{function}.png"
        save_as_png(source_cfgs[function], output_file)

    for decompiler in args.decs:
        filename = f"{decompiler}_{basename}.c"
        filepath = dec_dir_path / filename
        dec_cfgs = cfgs_from_source(filepath)

        func_cfg = dec_cfgs[function]
        dist = compute_cfg_edit_distance(func_cfg, source_cfgs[function], function, binary_path, decompiler)
        upper_ged = ged_upperbound_score(function, None, source_cfgs=source_cfgs, dec_cfgs=dec_cfgs)
        print(f"Decompiler: {decompiler} Target: {basename} - {function} | CFGED: {dist} | O-GED: {upper_ged}")
        if args.save_png:
            save_as_png(func_cfg, dec_dir_path / f"{decompiler}_{basename}_{function}.png")
