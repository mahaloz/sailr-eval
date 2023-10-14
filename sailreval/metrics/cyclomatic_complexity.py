from typing import Dict
import networkx as nx


def cyclomatic_complexity(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph] = None, dec_cfgs: Dict[str, nx.DiGraph] = None,
    binary_path=None, decompiler=None, **kwargs
):
    if client is None and not dec_cfgs:
        return None

    if func_name not in dec_cfgs:
        return None

    func_cfg = dec_cfgs[func_name]

    # Cyclomatic Complexity = E - N + 2*C
    # E = edges
    # N = nodes
    # C = strongly connected graphs
    e = len(list(func_cfg.edges))
    n = len(list(func_cfg.nodes))
    cc = e - n + 2
    return cc
