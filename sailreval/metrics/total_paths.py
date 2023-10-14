from typing import List
import itertools
import sys

from .graph_utils import get_graph_root_nodes

import networkx as nx

memory = {}
ctr = itertools.count()


class DummyNode:
    def __init__(self):
        self.addr = next(ctr)
        self.path_count = 0

    def __eq__(self, other):
        return isinstance(other, DummyNode) and self.addr == other.addr

    def __hash__(self):
        return hash(self.addr)




#def count_paths(g, start_node, end_node):
#    if end_node == start_node:
#        return 1
#
#    if end_node in memory:
#        return memory[end_node]
#
#    nodes = g.predecessors(end_node)
#    total = 0
#    for node in nodes:
#        r = count_paths(g, start_node, node)
#        total += r
#    if isinstance(end_node, DummyNode):
#        total *= end_node.path_count
#    memory[end_node] = total
#    return total


#def count_total_paths(graph: nx.DiGraph):
#    global memory, ctr
#    memory = {}
#    ctr = itertools.count()
#
#    for component in list(nx.strongly_connected_components(graph)):
#        if len(component) > 1:
#            # create a subgraph
#            subgraph = graph.subgraph(component).copy()
#
#            all_predecessors = set()
#            all_successors = set()
#            loop_heads = []
#            for node in component:
#                for pred in graph.predecessors(node):
#                    if pred not in component:
#                        all_predecessors.add(pred)
#                        loop_heads.append(node)
#                for succ in graph.successors(node):
#                    if succ not in component:
#                        all_successors.add(succ)
#            new_node = DummyNode()
#            for pred in all_predecessors:
#                graph.add_edge(pred, new_node)
#            for succ in all_successors:
#                graph.add_edge(new_node, succ)
#            for nn in component:
#                graph.remove_node(nn)
#
#            # count the number of paths in the subgraph
#            # break the loop first
#            loop_head = loop_heads[0]
#            pred = list(subgraph.predecessors(loop_head))[0]
#            subgraph.remove_edge(pred, loop_head)
#            path_count = count_paths(subgraph, loop_head, pred)
#
#            # each loop iterates at most 6 times due to __nb_steps being 6 in this example program
#            path_count = path_count ** 6
#            new_node.path_count = path_count
#
#    # count number of paths
#    start_nodes = [node for node in graph.nodes if graph.in_degree(node) == 0]
#    start_nodes = get_graph_root_nodes(graph) if len(start_nodes) > 1 else start_nodes
#    start_node = start_nodes[0]
#    end_nodes = [node for node in graph.nodes if graph.out_degree(node) == 0]
#
#    total_paths = 0
#    for end_node in end_nodes:
#        total_paths += count_paths(graph, start_node, end_node)
#
#    return total_paths


def _all_simple_paths_graph(G, source, targets, cutoff):
    size = 0
    visited = dict.fromkeys([source])
    stack = [iter(G[source])]
    while stack:
        children = stack[-1]
        child = next(children, None)
        if child is None:
            stack.pop()
            visited.popitem()
        elif len(visited) < cutoff:
            if child in visited:
                continue
            if child in targets:
                size += len(list(visited)) + 1
            visited[child] = None
            if targets - set(visited.keys()):  # expand stack until find all targets
                stack.append(iter(G[child]))
            else:
                visited.popitem()  # maybe other ways to child
        else:  # len(visited) == cutoff:
            for target in (targets & (set(children) | {child})) - set(visited.keys()):
                size += len(list(visited)) + 1
            stack.pop()
            visited.popitem()

    return size

def count_total_paths(func_name, client, **kwargs):
    if client is None:
        return None

    graph = client.get_func_cfg(func_name)

    # count number of paths
    start_nodes = [node for node in graph.nodes if graph.in_degree(node) == 0]
    start_nodes = get_graph_root_nodes(graph) if len(start_nodes) > 1 else start_nodes
    start_node = start_nodes[0]
    end_nodes = {node for node in graph.nodes if graph.out_degree(node) == 0}
    count = _all_simple_paths_graph(graph, start_node, end_nodes, len(graph) - 1)

    return count
