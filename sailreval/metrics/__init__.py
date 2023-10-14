import logging

from .total_paths import count_total_paths
from .cyclomatic_complexity import cyclomatic_complexity
from .total_gotos import count_total_gotos
from .total_loc import count_total_loc
from .nesting_count import count_nesting_ifs
from .duplication import count_func_calls
from .total_bools import count_if_bools
from .ged_to_source import ged_upperbound_score, cfg_edit_distance, ged_max_score, block_count, ged_exact_score, graph_size
from .post_metrics import norm_cfged, zero_cfged, funcs_w_goto, goto_func_cfged

from sailreval import SAILR_METRICS

"""
Decompilation Metrics:
1. Count Gotos
2. Cyclomatic Complexity

Engineering Metrics:
1. Cyclomatic Complexity: how many control structures do you have?
2. Nesting Count: How complicated is each of those control structures?
3. Total Gotos: How many times did you fail to identify a structure? 
4. Total LoC: How much code you need to read?
5. Irreducible Count: How condensed is that code? <----- ?????
6. Total Paths: How many ways can you analyze the code?

#5 is hard because its unclear in decompilation what is irreducible.

"""

l = logging.getLogger(__name__)

METRICS = {
    # Graph Edit Distance variants
    SAILR_METRICS.GED_UPPERBOUND: ged_upperbound_score,
    SAILR_METRICS.GED_MAX: ged_max_score,
    SAILR_METRICS.GED_EXACT: ged_exact_score,

    # Important Metrics
    SAILR_METRICS.GOTO_COUNT: count_total_gotos,
    SAILR_METRICS.FUNC_CALLS: count_func_calls,
    SAILR_METRICS.CFGED: cfg_edit_distance,

    # Meta Metrics
    SAILR_METRICS.BLOCK_COUNT: block_count,
    SAILR_METRICS.GRAPH_SIZE: graph_size,
    SAILR_METRICS.DEC_TIME: lambda *args, **kwargs: kwargs.get(SAILR_METRICS.DEC_TIME, None),

    # Others
    SAILR_METRICS.PATH_COUNT: count_total_paths,
    SAILR_METRICS.CODE_COMPLEXITY: cyclomatic_complexity,
    SAILR_METRICS.LINES_OF_CODE: count_total_loc,
    SAILR_METRICS.IF_STMT_COUNT: count_nesting_ifs,
    SAILR_METRICS.BOOLEAN_COUNT: count_if_bools,
}

POST_METRICS = {
    SAILR_METRICS.NORM_CFGED: norm_cfged,
    SAILR_METRICS.ZERO_CFGED: zero_cfged,
    SAILR_METRICS.GOTO_FUNC_CFGED: goto_func_cfged,
    SAILR_METRICS.FUNCS_W_GOTO: funcs_w_goto
}


def get_metric_function(metric_name):
    metric_func = METRICS[metric_name]

    def _metric_for_functions(functions, client, **kwargs):
        output = {}
        for func_name in functions:
            try:
                output[func_name] = metric_func(func_name, client, **kwargs)
                timedout = False
            except Exception as e:
                l.critical(f"Failed to run metric function <{metric_func}>({kwargs.get('binary_path', None)}: {func_name}) because {e}")
                output[func_name] = None
                timedout = True

            # XXX: hotfix for get timout to have a max score in timeout event
            if timedout and metric_name in (SAILR_METRICS.GED_UPPERBOUND, SAILR_METRICS.CFGED):
                func_name, source_cfgs, dec_cfgs = kwargs.get("func_name", None), kwargs.get("source_cfgs", None), kwargs.get("dec_cfgs", None)
                if func_name and source_cfgs and dec_cfgs and func_name in source_cfgs and func_name in dec_cfgs:
                    src_cfg = source_cfgs[func_name]
                    dec_cfg = dec_cfgs[func_name]
                    output[func_name] = len(src_cfg.nodes) + len(src_cfg.edges) + len(dec_cfg.nodes) + len(dec_cfg.edges)

        return output

    return _metric_for_functions
