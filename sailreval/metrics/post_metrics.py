from typing import Dict, List, Tuple

from .. import SAILR_DECOMPILERS, SAILR_METRICS


def run_post_metrics(post_metrics: List[str], metric_list_by_decompiler: Dict[str, Dict[str, List[int]]]) -> Dict[str, Dict[str, List[int]]]:
    from . import POST_METRICS
    """
    Runs the post metrics on the metric_list_by_decompiler.
    """
    final_output = metric_list_by_decompiler.copy()
    for metric in post_metrics:
        if metric not in POST_METRICS:
            raise ValueError(f"Unknown post metric: {metric}")

        round_output = POST_METRICS[metric](final_output)
        for dec in round_output:
            final_output[dec][metric] = round_output[dec]

    return final_output


def goto_func_cfged(metric_list_by_decompiler: Dict[str, Dict[str, List[int]]]) -> Dict[str, Dict[str, List[int]]]:
    output, valid = _validate_metric_data([SAILR_METRICS.CFGED, SAILR_METRICS.GOTO_COUNT], metric_list_by_decompiler)
    if not valid or SAILR_DECOMPILERS.ANGR_PHOENIX not in metric_list_by_decompiler:
        return output

    # find functions with goto >= 1 in Phoenix
    goto_idxs = []
    for i, goto_count in enumerate(metric_list_by_decompiler[SAILR_DECOMPILERS.ANGR_PHOENIX][SAILR_METRICS.GOTO_COUNT]):
        if goto_count >= 1:
            goto_idxs.append(i)

    # get CFGED for those functions
    for dec, mdata in metric_list_by_decompiler.items():
        for i, cfged in enumerate(mdata[SAILR_METRICS.CFGED]):
            if i in goto_idxs:
                output[dec].append(cfged)

    return output


def norm_cfged(metric_list_by_decompiler: Dict[str, Dict[str, List[int]]]) -> Dict[str, Dict[str, List[int]]]:
    """
    Computes: CFGED / GRAPH_SIZE
    Requires: CFGED, GRAPH_SIZE
    """
    output, valid = _validate_metric_data([SAILR_METRICS.CFGED, SAILR_METRICS.GRAPH_SIZE], metric_list_by_decompiler)
    if not valid:
        return output

    for dec, mdata in metric_list_by_decompiler.items():
        for i, cfged in enumerate(mdata[SAILR_METRICS.CFGED]):
            output[dec].append(cfged / metric_list_by_decompiler[SAILR_DECOMPILERS.SOURCE_CODE][SAILR_METRICS.GRAPH_SIZE][i])

    return output


def zero_cfged(metric_list_by_decompiler: Dict[str, List[int]]) -> Dict[str, List[int]]:
    output, valid = _validate_metric_data([SAILR_METRICS.CFGED], metric_list_by_decompiler)
    if not valid:
        return output

    for dec, mdata in metric_list_by_decompiler.items():
        for cfged in mdata[SAILR_METRICS.CFGED]:
            output[dec].append(1 if cfged == 0 else 0)

    return output


def funcs_w_goto(metric_list_by_decompiler: Dict[str, List[int]]) -> Dict[str, List[int]]:
    output, valid = _validate_metric_data([SAILR_METRICS.GOTO_COUNT], metric_list_by_decompiler)
    if not valid:
        return output

    for dec, mdata in metric_list_by_decompiler.items():
        for gotos in mdata[SAILR_METRICS.GOTO_COUNT]:
            output[dec].append(1 if gotos >= 1 else 0)

    return output

#
# Utils
#

def _validate_metric_data(requires: List[str], metric_list_by_decompiler) -> Tuple[Dict, bool]:
    """
    Validates that the required metrics are in the metric_list_by_decompiler.
    """
    output = {dec: list() for dec in metric_list_by_decompiler}
    for dec, mdata in metric_list_by_decompiler.items():
        if any(m not in mdata for m in requires):
            return output, False

    return output, True
