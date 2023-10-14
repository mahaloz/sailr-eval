import os
import logging
from typing import Set

from cpgqls_client import CPGQLSClient, import_code_query
import networkx as nx
import pygraphviz as pg

l = logging.getLogger(__name__)


class JoernClient:
    def __init__(self, target_file, ip="localhost", port=9000, bin_name=None):
        self.ip = ip
        self.port = port
        self.target_file = target_file
        self.bin_name = bin_name or ""

        # connect and import target file
        self.client = CPGQLSClient(f"{ip}:{port}")
        self.client.execute(import_code_query(f"{self.target_file}", f"{os.path.basename(self.target_file)}"))
        self.functions: Set[str] = self._get_functions_with_code()

        # cache
        self.cfg_cache = {}

    #
    # Public API
    #
    
    def function_line_numbers(self):
        out = self._exec_list_cmd("cpg.method.filter(node => node.lineNumber!=None&&node.lineNumberEnd!=None).map(node => (node.name, node.lineNumber.last, node.lineNumberEnd.last)).l")
        if not out:
            return {}

        if not isinstance(out, (list, tuple)):
            return {}

        line_nums_by_func = {}
        for data in out:
            if not isinstance(data, (list, tuple)) or len(data) != 3:
                continue

            fn, ln_start, ln_end = data
            if fn not in self.functions:
                continue

            line_nums_by_func[fn] = (ln_start, ln_end)

        return line_nums_by_func

    def function_headers(self):
        headers = {}
        for func in self.functions:
            out = self._exec_list_cmd(f'cpg.method("{func}").code.l')
            if not out:
                continue

            if not isinstance(out, (list, tuple)):
                continue

            headers[func] = out[0]

        return headers
    
    def functions_with_gotos(self):
        out1 = self._exec_list_cmd(f'cpg.goto.method.name.l')
        if not out1:
            return []

        if isinstance(out1, (list, tuple)) and len(out1) > 0:
            return out1

        return []
        
    def functions_with_switches(self):
        out1 = self._exec_list_cmd(f'cpg.switchBlock.method.name.l')
        if not out1:
            return []

        if isinstance(out1, (list, tuple)) and len(out1) > 0:
            return out1

        return []

    def get_func_cfg(self, func_name):
        if func_name in self.cfg_cache:
            return self.cfg_cache[func_name]

        cfg = self._dump_func_cfg(func_name)
        self.cfg_cache[func_name] = cfg

        return cfg

    def get_func_loc(self, func_name):
        """
        Gets a functions lines of code (loc) count.
        """
        if func_name not in self.functions:
            return None

        out1 = self._exec_list_cmd(f'cpg.method.name("{func_name}").lineNumber.l')
        if out1 is None:
            return None

        out2 = self._exec_list_cmd(f'cpg.method.name("{func_name}").lineNumberEnd.l')
        if out2 is None:
            return None

        start_line = out1[-1] if not isinstance(out1, int) else out1
        end_line = out2[-1] if not isinstance(out2, int) else out2

        try:
            val = int(end_line) - int(start_line)
        except Exception:
            return None
        return val
    
    def function_ternary_counts(self):
        count = {}
        for func_name in self.functions:
            out = self._exec_int_cmd(f'cpg.method("{func_name}").call.filter(_.name=="<operator>.conditional").filter(_.code.contains("__builtin_unreachable")==false).size')
            if out is None:
                continue
            count[func_name] = out 

        return count
            

    def count_gotos(self, func_name):
        if func_name not in self.functions:
            return None

        out = self._exec_int_cmd(f'cpg.method("{func_name}").goto.size')
        if out is None:
            return None

        return out

    def count_if_levels(self, func_name):
        """
        Returns the max of if-nesting level

        """
        out = self._exec_list_cmd(
            f'cpg.method("{func_name}").controlStructure.controlStructureType("IF").depth(_.isControlStructure).l'
        )
        if out is None or (isinstance(out, (list, tuple)) and len(out) == 0):
            return None

        # if_count = out if isinstance(out, int) else sum(out) // len(out)
        if_count = out if isinstance(out, int) else max(out)
        return if_count

    def func_calls_in_func(self, func_name):
        out = self._exec_list_cmd(
            f'cpg.method("{func_name}").call.name.l'
        )
        if out is None:
            return None

        out = [out] if isinstance(out, str) else out
        good_funcs = self._filter_blacklisted(out)
        return good_funcs
    
    def get_control_structure_conditions(self, func_name):
        if func_name not in self.functions:
            return None

        out = self._exec_list_cmd(
            f'cpg.method("{func_name}").controlStructure.condition.code.l'
        )
        if not isinstance(out, (tuple, list)):
            return None

        return list(out)

    #
    # Private Helpers
    #

    def _get_functions_with_code(self):
        out = self._exec_list_cmd(
            "cpg.method.filter(node => node.lineNumber!=None&&node.lineNumberEnd!=None&&node.lineNumber!=node.lineNumberEnd).name.l"
        )
        if not isinstance(out, (tuple, list)):
            return []

        out = list(out)
        return set(self._filter_blacklisted(out))

    @staticmethod
    def _filter_blacklisted(strings):
        blacklist = [
            "<", "+", "*", "(", ">", "JUMPOUT", "__builtin_unreachable"
        ]
        good_strings = []
        for string in strings:
            if not any(string.startswith(b) for b in blacklist):
                good_strings.append(string)

        return good_strings

    def _exec_list_cmd(self, raw_command):
        res = self.client.execute(f"show({raw_command})")
        tuple_str = self._get_str_tuple(res, cmd=raw_command)
        return tuple_str

    def _exec_int_cmd(self, raw_command):
        res = self.client.execute(f"show({raw_command})")
        int_val = self._get_str_int(res, cmd=raw_command)
        if int_val is None or not isinstance(int_val, int):
            return None

        return int_val

    def _get_str_int(self, req_res, cmd=None):
        if 'stdout' not in req_res:
            return None

        out = None
        try:
            raw_out = req_res['stdout']
            out = int(raw_out, 10)
        except Exception as e:
            l.warning(f"Error occurred doing JOERN eval for {self.bin_name} on {cmd} because {e}")

        return out

    def _get_str_tuple(self, req_res, cmd=None):
        if 'stdout' not in req_res:
            return None

        try:
            raw_out = req_res['stdout'].split("List(")[-1]
            str_tuple = eval("(" + raw_out)
        except Exception as e:
            l.warning(f"Error occurred doing JOERN eval for {self.bin_name} on {cmd} because {e}")
            return None

        if type(str_tuple) == str:
            str_tuple = [str_tuple]

        return str_tuple

    def _dump_func_cfg(self, func_name):
        str_tuple = self._exec_list_cmd(f'cpg.method("{func_name}").dotCfg.l')
        try:
            graph = nx.nx_agraph.from_agraph(pg.AGraph(str_tuple[-1]))
        except Exception as e:
            l.warning(f"Error getting CFG from JOERN for {self.bin_name} on {func_name} as {e}")
            graph = None

        return graph
