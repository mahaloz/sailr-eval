from textwrap import dedent
from typing import Union, List

import networkx as nx

from .statement import MergedRegionStart

#
# Blocks
#

class Block:
    def __init__(self, addr, statements=None, idx=None):
        self.addr = addr
        self.idx = idx
        self.statements = statements or list()
        self.idx_str = "" if self.idx is None else f".{self.idx}"

    def __eq__(self, other):
        return isinstance(other, Block) and self.addr == other.addr and self.statements == other.statements

    def __hash__(self):
        return hash(f"{self.addr}{self.idx}{[stmt for stmt in self.statements]}")

    def __repr__(self):
        return f"<Block: {self.addr}{self.idx_str}, {len(self.statements)} statements>"

    def __str__(self):
        output = f"{self.addr}{self.idx_str}:\n"
        for line in self.statements:
            output += f"{line}\n"

        return output

    def copy(self):
        return Block(
            self.addr,
            statements=[stmt.copy() for stmt in self.statements],
            idx=self.idx
        )
    
    def contains_addr(self, addr):
        if self.addr == addr:
            return True
        
        for stmt in self.statements:
            if stmt.source_line_number == addr:
                return True

        return False

    @staticmethod
    def merge_blocks(block1: "Block", block2: "Block", graph: nx.DiGraph = None, update_graph=True) -> \
            Union["Block", nx.DiGraph]:
        """
        Merges to JIL blocks. When update_graph is true, the graph will be modified to reflect this.
        This implementation assumes block1 is the parent of block2 for graph updates.

        :param block1:
        :param block2:
        :param graph:
        :param update_graph:
        :return:
        """

        new_node = block1
        new_node.statements += block2.statements
        if not update_graph or graph is None:
            return new_node

        in_edges = list(graph.in_edges(block1))
        out_edges = list(graph.out_edges(block2))
        graph.remove_node(block1)
        graph.remove_node(block2)

        if new_node is not None:
            graph.add_node(block1)

            for src, _ in in_edges:
                if src is block2:
                    src = new_node
                graph.add_edge(src, new_node)

            for _, dst in out_edges:
                if dst is block1:
                    dst = new_node
                graph.add_edge(new_node, dst)

        return new_node


def make_merge_block(addr, nodes: List[Block]):
    node_count = 0
    stmts = list()
    for node in nodes:
        for stmt in node.statements:
            node_count += stmt.total_nodes if isinstance(stmts, MergedRegionStart) else 1
            stmts.append(stmt)

    return Block(
        addr,
        statements=[MergedRegionStart(source_line_number=addr, total_nodes=node_count)] + stmts
    )
