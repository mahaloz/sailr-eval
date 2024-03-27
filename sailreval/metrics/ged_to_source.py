import logging
from pathlib import Path
from typing import Dict

from cfgutils.similarity import ged_max, ged_upperbound, ged_exact
from cfgutils.similarity import cfg_edit_distance as _cfg_edit_distance
import networkx as nx

l = logging.getLogger(__name__)
MAX_EXACT_NODES = 12

#
# Graph Edit Distance Variants
#


def ged_exact_score(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph] = None, dec_cfgs: Dict[str, nx.DiGraph] = None,
    decompiler=None, binary_path=None, **kwargs
):
    """
    Computes the exact GED for a given function.
    """
    if decompiler == "source":
        return float(0)
    source_cfg, dec_cfg = _verify_has_valid_graphs(func_name, client, source_cfgs, dec_cfgs, decompiler, binary_path)
    if source_cfg is None or dec_cfg is None:
        return None

    return ged_exact(dec_cfg, source_cfg, check_max=True)


def ged_upperbound_score(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph] = None, dec_cfgs: Dict[str, nx.DiGraph] = None,
    decompiler=None, binary_path=None, **kwargs
):
    """
    Collects the upperbound fastest approximation of GED for a given function. This is a highly innacurate metric.
    """
    if decompiler == "source":
        return float(0)
    source_cfg, dec_cfg = _verify_has_valid_graphs(func_name, client, source_cfgs, dec_cfgs, decompiler, binary_path)
    if source_cfg is None or dec_cfg is None:
        return None

    return ged_upperbound(dec_cfg, source_cfg)


def ged_max_score(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph] = None, dec_cfgs: Dict[str, nx.DiGraph] = None,
    binary_path=None, decompiler=None, **kwargs
):
    """
    Computes the MAXIMUM possible score that GED could return for a given function.
    Notice, this score is just a summation of all edges and nodes from both graphs.
    """
    source_cfg, dec_cfg = _verify_has_valid_graphs(func_name, client, source_cfgs, dec_cfgs, decompiler, binary_path)
    if source_cfg is None or dec_cfg is None:
        return None

    return ged_max(dec_cfg, source_cfg)


#
# CFG Edit Distance
#


def cfg_edit_distance(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph] = None, dec_cfgs: Dict[str, nx.DiGraph] = None,
    binary_path=None, decompiler=None, **kwargs
):
    if decompiler == "source":
        return float(0)
    source_cfg, dec_cfg = _verify_has_valid_graphs(func_name, client, source_cfgs, dec_cfgs, decompiler, binary_path)
    if source_cfg is None or dec_cfg is None:
        return None

    return compute_cfg_edit_distance(dec_cfg, source_cfg, func_name, binary_path, decompiler)


def compute_cfg_edit_distance(dec_cfg, src_cfg, function, binary_path: Path, decompiler: str):
    from pyjoern.mapping import correct_decompiler_mappings, read_line_maps
    binary_path = Path(binary_path)
    bin_dir = binary_path.parent
    bin_name = binary_path.with_suffix("").name

    src_addr_to_line_map = read_line_maps(binary_path.with_suffix(".dwarf.linemaps"), key_is_func=False, value_is_set_type=False)
    if not src_addr_to_line_map:
        return None

    dec_line_to_addr_map = read_line_maps(bin_dir.joinpath(f"{decompiler}_{bin_name}.linemaps"))
    if not dec_line_to_addr_map:
        return None
    func_line_to_addr_map = dec_line_to_addr_map.get(function, None)
    if func_line_to_addr_map is None:
        return None

    dec_line_to_addr_map = correct_decompiler_mappings(dec_cfg, func_line_to_addr_map)
    return _cfg_edit_distance(dec_cfg, src_cfg, dec_line_to_addr_map, src_addr_to_line_map)


def has_cfged_required_src_files(source_path: Path, binary_path: Path):
    dwarf_linemaps = binary_path.with_suffix(".dwarf.linemaps").absolute()
    return dwarf_linemaps.exists() and has_cfged_required_files(source_path)


def has_cfged_required_files(source_path: Path):
    source_linemaps = source_path.with_suffix(".linemaps").absolute()
    return source_linemaps.exists()

#
# Others
#


def _verify_has_valid_graphs(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph], dec_cfgs: Dict[str, nx.DiGraph], decompiler, binary_path
):
    if client is not None:
        if func_name not in client.functions:
            return None, None

        if not source_cfgs or not dec_cfgs:
            return None, None

    source_cfg = source_cfgs.get(func_name, None)
    dec_cfg = dec_cfgs.get(func_name, None)
    if source_cfg is None or dec_cfg is None:
        l.debug(f"CFGs are none for {decompiler} on {func_name} in {binary_path}")
        return None, None
    elif len(source_cfg.nodes) == 0:
        l.debug(f"Empty CFG on source for {func_name} in {binary_path}")
        return None
    elif len(dec_cfg.nodes) == 0:
        l.debug(f"Empty CFG on {decompiler} for {func_name} in {binary_path}")
        return None, None

    return source_cfg, dec_cfg


def graph_size(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph] = None, dec_cfgs: Dict[str, nx.DiGraph] = None,
    binary_path=None, decompiler=None, **kwargs
):
    dec_cfg = dec_cfgs.get(func_name, None)
    if dec_cfg is None:
        return None

    return len(dec_cfg.nodes) + len(dec_cfg.edges)


def block_count(
    func_name, client, source_cfgs: Dict[str, nx.DiGraph] = None, dec_cfgs: Dict[str, nx.DiGraph] = None,
    binary_path=None, decompiler=None, **kwargs
):
    dec_cfg = dec_cfgs.get(func_name, None)
    if dec_cfg is None:
        l.debug(f"CFGs are none for {decompiler} on {func_name} in {binary_path}")
        return None

    return len(dec_cfg.nodes)
