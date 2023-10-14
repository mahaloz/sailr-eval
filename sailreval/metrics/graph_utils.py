import networkx as nx

def get_graph_root_nodes(graph: nx.DiGraph, **kwargs):
    initial_roots = [n for n in graph.nodes if graph.in_degree(n) == 0]
    roots = []
    for ir in initial_roots:
        label = graph._node[ir]['label']
        if label.startswith(f"(METHOD,{graph.name}") and "SUB" in label:
            roots.append(ir)

    return roots