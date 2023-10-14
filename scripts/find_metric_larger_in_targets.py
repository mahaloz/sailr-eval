from pathlib import Path

from sailreval.analysis.counting import load_tomls_by_bin_name
from sailreval.utils.sailr_target import SAILRTarget
from sailreval.utils.compile import OPTIMIZATION_LEVELS
from sailreval.utils import SAILR_COMPILATION_RESULTS_DIR, SAILR_DECOMPILATION_RESULTS_DIR, SAILR_MEASURE_RESULTS_DIR


LARGE_EVAL_TARGETS_STRING = ('bash libselinux shadow libedit base-passwd openssh-portable dpkg dash grep kmod '
                             'diffutils findutils gnutls iproute2 gzip sysvinit bzip2 libacl libexpat libbsd libassuan '
                             'tar rsyslog cronie zlib e2fsprogs coreutils')
LARGE_EVAL_TARGET_NAMES = LARGE_EVAL_TARGETS_STRING.split(" ")


def iterate_all_targets(target_names, opt_levels=OPTIMIZATION_LEVELS, results_location="./results"):
    """
    Returns: (sailr_target, sailr_target_dir, sailr_compile_dir, sailr_decompile_dir, sailr_measure_dir)
    """
    out = {}
    for target_name in target_names:
        for opt_level in opt_levels:
            sailr_target = SAILRTarget.from_toml(f"./targets/{target_name}.toml")
            sailr_target_dir = Path(f"{results_location}/{opt_level}/").joinpath(sailr_target.package_dir).absolute()
            sailr_compile_dir = sailr_target_dir.joinpath(SAILR_COMPILATION_RESULTS_DIR).absolute()
            sailr_decompile_dir = sailr_target_dir.joinpath(SAILR_DECOMPILATION_RESULTS_DIR).absolute()
            sailr_measure_dir = sailr_target_dir.joinpath(SAILR_MEASURE_RESULTS_DIR).absolute()

            out[sailr_target.package_name] = (
                sailr_target, sailr_target_dir, sailr_compile_dir, sailr_decompile_dir, sailr_measure_dir
            )

    return out

def _format_number(num):
    if isinstance(num, str):
        return int(float(num))

    return num

def find_metric_lower_in_prev_results(prev_dec="angr_phoenix", new_dec="angr_sailr", metric="cfged"):
    opt_levels = ["O2"]
    prev_results = iterate_all_targets(LARGE_EVAL_TARGET_NAMES, results_location="./results", opt_levels=opt_levels)
    new_results = iterate_all_targets(LARGE_EVAL_TARGET_NAMES, results_location="./results", opt_levels=opt_levels)
    
    output_str = ""
    hits = {}
    for target_name in LARGE_EVAL_TARGET_NAMES:
        prev_target = prev_results[target_name]
        new_target = new_results[target_name]
        prev_measure_dir = prev_target[-1]
        new_measure_dir = new_target[-1]

        s = f"======= COMPARING {new_measure_dir} > {prev_measure_dir} ========"
        #output_str += s + "\n"
        print(s)
        prev_data_by_bin_name = load_tomls_by_bin_name(prev_measure_dir)
        new_data_by_bin_name = load_tomls_by_bin_name(new_measure_dir)

        for bin_name, bin_data in prev_data_by_bin_name.items():
            prev_metric = bin_data.get(prev_dec, {}).get(metric, None)
            new_metric = new_data_by_bin_name.get(bin_name, {}).get(new_dec, {}).get(metric, None)
            src_metric = bin_data.get("source", {}).get(metric, None)

            if new_metric is None or prev_metric is None or src_metric is None:
                continue

            for func, old_score in prev_metric.items():
                if func not in new_metric or func not in src_metric:
                    continue

                old_score = _format_number(old_score)
                new_score = _format_number(new_metric[func])
                if new_score > old_score:
                    diff = new_score - old_score
                    out_str = f"{bin_name}.{func}: {new_dec}:{new_score} > {prev_dec}:{old_score} ({target_name})"
                    hits[out_str] = diff

    for hit, diff in sorted(hits.items(), key=lambda x: x[1], reverse=True):
        s = str(hit)
        output_str += s + "\n"
        print(s)
    
    with open("gotos_bigger_now.txt", "w") as fp:
        fp.write(output_str)


def find_metric_and_other_lower_in_prev_results(
    prev_dec="angr_sailr", new_dec="angr_sailr", metric="gotos", other_metric="cfged"
):
    opt_levels = ["O2"]
    prev_results = iterate_all_targets(LARGE_EVAL_TARGET_NAMES, results_location="./prev_results",
                                       opt_levels=opt_levels)
    new_results = iterate_all_targets(LARGE_EVAL_TARGET_NAMES, results_location="./results", opt_levels=opt_levels)

    output_str = ""
    for target_name in LARGE_EVAL_TARGET_NAMES:
        prev_target = prev_results[target_name]
        new_target = new_results[target_name]
        prev_measure_dir = prev_target[-1]
        new_measure_dir = new_target[-1]

        s = f"======= COMPARING {new_measure_dir} > {prev_measure_dir} ========"
        output_str += s + "\n"
        print(s)
        prev_data_by_bin_name = load_tomls_by_bin_name(prev_measure_dir)
        new_data_by_bin_name = load_tomls_by_bin_name(new_measure_dir)

        hits = {}
        for bin_name, bin_data in prev_data_by_bin_name.items():
            prev_metric = bin_data.get(prev_dec, {}).get(metric, None)
            new_metric = new_data_by_bin_name.get(bin_name, {}).get(new_dec, {}).get(metric, None)
            other_prev_metric = bin_data.get(prev_dec, {}).get(other_metric, None)
            other_new_metric = new_data_by_bin_name.get(bin_name, {}).get(new_dec, {}).get(other_metric, None)

            if new_metric is None or prev_metric is None or other_prev_metric is None or other_new_metric is None:
                continue

            for func, old_score in prev_metric.items():
                if func not in new_metric or func not in other_prev_metric or func not in other_new_metric:
                    continue

                old_score = _format_number(old_score)
                new_score = _format_number(new_metric[func])
                other_old_score = _format_number(other_prev_metric[func])
                other_new_score = _format_number(other_new_metric[func])
                if new_score > old_score and other_new_score >= other_old_score:
                    diff = new_score - old_score
                    out_str = f"{bin_name}.{func} | {metric}: {new_dec}:{new_score} > {prev_dec}:{old_score} | {other_metric}: {new_dec}:{other_new_score} >= {prev_dec}:{other_old_score}"
                    hits[out_str] = diff

        for hit, diff in sorted(hits.items(), key=lambda x: x[1], reverse=True):
            s = str(hit)
            output_str += s + "\n"
            print(s)

    with open("gotos_bigger_now.txt", "w") as fp:
        fp.write(output_str)

#find_metric_and_other_lower_in_prev_results()
find_metric_lower_in_prev_results()
