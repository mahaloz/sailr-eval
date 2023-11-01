__version__ = "1.2.0"

# create loggers
import logging
logging.getLogger("sailreval").addHandler(logging.NullHandler())
from sailreval.loggercfg import Loggers
loggers = Loggers()
del Loggers

l = logging.getLogger(__name__)


class SAILR_METRICS:
    CODE_COMPLEXITY = "cc"
    GOTO_COUNT = "gotos"
    LINES_OF_CODE = "loc"
    IF_STMT_COUNT = "ifs"
    FUNC_CALLS = "func_calls"
    PATH_COUNT = "paths"
    BOOLEAN_COUNT = "bools"
    GED_UPPERBOUND = "ged_upperbound"
    GED_MAX = "ged_max"
    GED_EXACT = "ged_exact"
    CFGED = "cfged"
    GRAPH_SIZE = "graph_size"
    BLOCK_COUNT = "block_count"
    DEC_TIME = "dec_time"

    # Post Metrics
    NORM_CFGED = "norm_cfged"               # CFGED / GRAPH_SZE
    ZERO_CFGED = "zero_cfged"               # count of CFGED == 0
    FUNCS_W_GOTO = "funcs_w_goto"           # count of goto >= 1
    GOTO_FUNC_CFGED = "goto_func_cfged"     # CFGED of functions with goto >= 1



class SAILR_DECOMPILERS:
    SOURCE_CODE = "source"
    SOURCE_EXPANDED_CODE = "expanded_source"
    ANGR_SAILR = "angr_sailr"
    ANGR_IMPROVED_PHOENIX = "angr_improved_phoenix"
    ANGR_PHOENIX = "angr_phoenix"
    ANGR_DREAM = "angr_dream"
    ANGR_COMB = "angr_comb"
    IDA = "ida"
    GHIDRA = "ghidra"


ALL_METRICS = [getattr(SAILR_METRICS, a) for a in dir(SAILR_METRICS) if not a.startswith("_")]
ALL_DECOMPILERS = [getattr(SAILR_DECOMPILERS, a) for a in dir(SAILR_DECOMPILERS) if not a.startswith("_")]
# TODO: this can be bad if people run it not in our pipeline
JOERNLESS_SERVER_METRICS = [SAILR_METRICS.CFGED, SAILR_METRICS.GED_UPPERBOUND, SAILR_METRICS.GED_MAX,
                            SAILR_METRICS.GED_EXACT, SAILR_METRICS.BLOCK_COUNT, SAILR_METRICS.DEC_TIME,
                            SAILR_METRICS.CODE_COMPLEXITY]

