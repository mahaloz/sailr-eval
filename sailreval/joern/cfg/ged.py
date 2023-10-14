import re
from collections import defaultdict
import logging

import networkx as nx

from .jil.block import Block
from .jil.statement import (
    Statement, Assignment, Compare, Call, Nop
)
from .utils import find_function_root_node
from sailreval.utils import timeout

_l = logging.getLogger(__name__)
MAX_NODES_FOR_EXACT_GED = 10
INVALID_CHOICE_PENALTY = 100000

#
# Helpers
#


def _collect_graph_roots(g1, g2):
    g1_start, g2_start = find_function_root_node(g1), find_function_root_node(g2)
    if g1_start is not None and g2_start is not None:
        roots = (g1_start, g2_start,)
    else:
        roots = None

    return roots


#
# Edit distance
#

def ged_max(g1, g2):
    return len(g1.nodes) + len(g1.edges) + len(g2.nodes) + len(g2.edges)


def ged_exact(g1, g2, with_timeout=10):
    """
    Computes the exact Graph Edit Distance for two graphs. On the event of a timeout,
    a score of None is returned.
    """
    if len(g1.nodes) > MAX_NODES_FOR_EXACT_GED or len(g2.nodes) > MAX_NODES_FOR_EXACT_GED:
        return None

    return graph_edit_distance_core_analysis(g1, g2, with_timeout=with_timeout, exact_score=True)


def ged_upperbound(g1, g2, with_timeout=5):
    """
    Does a single iterations of the GED algorithm and returns the upperbound.
    Note: this is not the max possible score.
    """
    return graph_edit_distance_core_analysis(g1, g2, upperbound_approx=True, with_timeout=with_timeout)


def graph_edit_distance_core_analysis(
    g1: nx.DiGraph, g2: nx.DiGraph, is_cfg=True, upperbound_approx=False, exact_score=False, with_timeout=10,
    penalize_root_exit_edits=True, recover_on_invalid_edits=True
):
    roots = _collect_graph_roots(g1, g2) if is_cfg else None

    # edge insertion cost
    def _edge_ins_cost(*args): return 1
    # node deletion cost
    def _node_del_cost(*args): return 1

    if is_cfg:
        def _edge_ins_cost(*args):
            """
            Makes it illegal to add edges to pred of function start or succ of function end
            (with exception of self loops)
            """
            attrs = args[0]
            src = attrs.get('src', None)
            dst = attrs.get('dst', None)
            if penalize_root_exit_edits:
                if src and src.statements:
                    last_stmt = src.statements[-1]
                    if isinstance(last_stmt, Nop) and last_stmt.type == Nop.FUNC_END and src is not dst:
                        return INVALID_CHOICE_PENALTY
                elif dst and dst.statements:
                    first_stmt = dst.statements[0]
                    if isinstance(first_stmt, Nop) and first_stmt.type == Nop.FUNC_START and dst is not src:
                        return INVALID_CHOICE_PENALTY

            return 1

        def _node_del_cost(*args):
            """
            Makes it illegal to delete function start nodes or end nodes
            """
            node = args[0].get('node', None)
            if penalize_root_exit_edits and node and node.statements:
                first_stmt = node.statements[0]
                last_stmt = node.statements[-1]
                if isinstance(first_stmt, Nop) and first_stmt.type == Nop.FUNC_START:
                    return INVALID_CHOICE_PENALTY
                elif isinstance(last_stmt, Nop) and last_stmt.type == Nop.FUNC_END:
                    return INVALID_CHOICE_PENALTY

            return 1

    if exact_score or upperbound_approx:
        try:
            with timeout(seconds=with_timeout):
                if upperbound_approx:
                    dist = next(nx.optimize_graph_edit_distance(g1, g2, node_del_cost=_node_del_cost, edge_ins_cost=_edge_ins_cost))
                else:
                    dist = nx.graph_edit_distance(g1, g2, roots=roots, node_del_cost=_node_del_cost, edge_ins_cost=_edge_ins_cost)
        except TimeoutError:
            dist = None
    else:
        dist = nx.graph_edit_distance(
            g1, g2, roots=roots, node_del_cost=_node_del_cost, edge_ins_cost=_edge_ins_cost, timeout=with_timeout
        )

    # sometimes the score can be computed wrong, which we can fix with a recompute ONCE
    if dist is not None and dist > INVALID_CHOICE_PENALTY and recover_on_invalid_edits:
        dist = graph_edit_distance_core_analysis(
            g1, g2, is_cfg=is_cfg, upperbound_approx=upperbound_approx, exact_score=exact_score,
            with_timeout=with_timeout, penalize_root_exit_edits=False, recover_on_invalid_edits=False
        )

    return dist

