import re
from typing import Dict, List
from collections import defaultdict
import logging

from .block import Block
from .statement import (
    UnsupportedStmt, UnknownStmt, Assignment, Compare, BinOp, Return, Call, Ternary, Nop
)

import networkx as nx

l = logging.getLogger(__name__)

STMT_MAP = {
    "assignment": (Assignment, None),
    "minus": (BinOp, BinOp.SUB),
    "plus": (BinOp, BinOp.ADD),
    "logicalAnd": (BinOp, BinOp.AND),
    "logicalOr": (BinOp, BinOp.OR),
    "equals": (Compare, Compare.EQ),
    "greaterEqualsThan": (Compare, Compare.GTE),
    "greaterThan": (Compare, Compare.GT),
    "lessEqualsThan": (Compare, Compare.LTE),
    "lessThan": (Compare, Compare.LT),
    "notEquals": (Compare, Compare.NE),
    "return": (Return, None),
    "call": (Call, None),
    "conditional": (Ternary, None),
}


def lift_graph(graph: nx.DiGraph):
    lifted_graph = nx.DiGraph()
    edges_by_node_addr: Dict[int, List[int]] = defaultdict(list)
    for (in_node, out_node) in graph.edges:
        edges_by_node_addr[in_node].append(out_node)

    addr_uses = defaultdict(int)
    new_blocks = {
        node: lift_block(node, graph, addr_dict=addr_uses) for node in graph.nodes
    }

    for node_name, new_node in new_blocks.items():
        for out_node in edges_by_node_addr[node_name]:
            new_out_block = new_blocks[out_node]
            lifted_graph.add_edge(new_node, new_out_block)

    return lifted_graph


def lift_block(node, graph, addr_dict=None):
    node_data = graph._node[node].get('label', None)
    if not node_data:
        new_addr = 0 - int(node, 10)
        new_idx = addr_dict[new_addr]
        addr_dict[new_addr] += 1
        return Block(0 - int(node, 10), statements=[Nop("", Nop.NOP)], idx=new_idx)

    statements = []
    for raw_stmt in node_data.split("\n"):
        try:
            lifted_stmt = lift_statement(raw_stmt)
        except Exception as e:
            l.debug(f"Encountered error while lifting: {e}")
            lifted_stmt = UnsupportedStmt(raw_stmt)

        statements.append(lifted_stmt)

    new_addr = statements[0].source_line_number
    new_idx = addr_dict[new_addr]
    addr_dict[new_addr] += 1
    return Block(new_addr, statements=statements, idx=new_idx)


def lift_statement(raw_data: str):
    source_line_number = re.findall("<SUB>([0-9]+)</SUB>", raw_data)
    if source_line_number:
        source_line_number = int(source_line_number[0], 10)
    else:
        l.debug(f"Failed to parse line number of node!")
        source_line_number = None
    line_num_kwarg = {"source_line_number": source_line_number}

    _t = "(".join(raw_data.split("(")[1:])
    raw_stmt = "".join(_t.split(")<SUB>")[0:-1]).replace(" ", "")

    # statement
    is_stmt = True
    stmt_type = None
    if raw_stmt.startswith("&lt;operator&gt;."):
        # &lt;operator&gt;.lessEqualsThan,v0 &lt;= line_buf
        t = raw_stmt.split("&lt;operator&gt;.")[1]
        t = t.split(",")
        stmt_type = t[0]
    elif raw_stmt.startswith("RETURN"):
        t = raw_stmt.split("RETURN")[1]
        t = t.split(",")
        stmt_type = "return"
    elif raw_stmt.startswith("METHOD_RETURN"):
        return Nop(raw_stmt, Nop.FUNC_END, **line_num_kwarg)
    elif raw_stmt.startswith("METHOD"):
        return Nop(raw_stmt, Nop.FUNC_START, **line_num_kwarg)
    else:
        is_stmt = False

    if is_stmt:
        # [lessEqualsThan], [v0 &lt;= line_buf],...
        raw_ops = ",".join(t[1:])
        # v0 &lt;= line_buf ...


        (jil_stmt_cls, sub_type) = STMT_MAP.get(stmt_type, (UnsupportedStmt, None))
        ops = []
        if jil_stmt_cls != UnsupportedStmt:
            sep = jil_stmt_cls.op_seperator(sub_type)
            if sep:
                out = raw_ops.split(sep)
                if not out[0]:
                    ops = [f"{sep}".join(out[1:])]
                else:
                    ops = out[0:1] + [f"{sep}".join(out[1:])]

        # specific parsers
        if jil_stmt_cls in (Compare, BinOp):
            return jil_stmt_cls(t, sub_type, *ops, **line_num_kwarg)
        # SPECIAL CASE: ternary
        elif jil_stmt_cls == Ternary:
            t = raw_ops.split("?")
            cond = t[0]
            t = "?".join(t)
            t.split(":")
            true = t[0]
            false = t[1]
            return Ternary(raw_stmt, cond, true, false, **line_num_kwarg)
        else:
            return jil_stmt_cls(t, *ops, **line_num_kwarg)
    else:
        t = raw_stmt.replace(" ", "")

        # check if call
        try:
            t_no_comma = t.split(",")
            is_call = t_no_comma and t_no_comma[0] == t_no_comma[1].split("(")[0]
        except (KeyError, IndexError):
            is_call = False
        if is_call:
            raw_call = t_no_comma[1]
            func = raw_call.split("(")[0]
            raw_args = "(".join(raw_call.split("(")[1:])
            raw_args = ")".join(raw_args.split(")")[:-1])
            args = raw_args.split(",")
            return Call(raw_stmt, func, args, **line_num_kwarg)

    return UnsupportedStmt(raw_stmt, **line_num_kwarg)
