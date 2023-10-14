from typing import List


def count_if_bools(func_name, client, **kwargs):
    if client is None:
        return None

    if func_name not in client.functions:
        return None

    condition_codes: List[str] = client.get_control_structure_conditions(func_name)
    if condition_codes is None:
        return None

    count = {"or": 0, "and": 0}
    for code in condition_codes:
        count["or"] += code.count("||")
        count["and"] += code.count("&&")

    return count
