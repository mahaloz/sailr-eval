#!/usr/bin/env python3
import argparse

from sailreval.decompilers.angr_dec import (
    angr_decompile,
    angr_improved_phoenix_decompile,
    angr_phoenix_decompile,
    angr_dream_decompile,
    angr_comb_decompile,
)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="""
        Runs the angr decompiler on a binary for a function. If you want to decompile all functions, pass 'None' as the function name.
        """,
        epilog="""
        Example usage: ./run_angr_dec.py ./motivating_example schedule_job --structuring-algo sailr
        """
    )
    parser.add_argument(
        'binary_path', help="Path to the binary to decompile"
    )
    parser.add_argument(
        'func', help="Name of the function to decompile. Pass 'None' if you want all.", default=None
    )
    parser.add_argument(
        '--structuring-algo', help="Structuring algorithm to use", default="sailr",
        choices=["sailr", "improved_phoenix", "phoenix", "dream", "combing"]
    )
    parser.add_argument(
        '--save-file', help="Saves the decompilation as a file named {binary_name}.c", action="store_true", default=False
    )
    parser.add_argument(
        '--save-metrics', help="""
        Saves the linemaps and precomputed metrics of the decompilation. Only useful in SAILR evaluation.
        """, action="store_true", default=False
    )

    args = parser.parse_args()
    if args.func == "None":
        args.func = None
    functions = [args.func] if args.func else None
    should_print = not args.save_file
    save_metrics = args.save_metrics
    filepath = args.binary_path
    dec_args = (filepath,)
    dec_kwargs = {
        "functions": functions, "print_dec": should_print, "dump_early_metrics": save_metrics,
        "dump_line_maps": save_metrics
    }
    if args.structuring_algo == "sailr":
        decompiler = angr_decompile
    elif args.structuring_algo == "phoenix":
        decompiler = angr_phoenix_decompile
    elif args.structuring_algo == "improved_phoenix":
        decompiler = angr_improved_phoenix_decompile
    elif args.structuring_algo == "dream":
        decompiler = angr_dream_decompile
    elif args.structuring_algo == "combing":
        decompiler = angr_comb_decompile
    else:
        raise ValueError(f"Unknown structuring algorithm: {args.structuring_algo}")

    decompiler(*dec_args, **dec_kwargs)