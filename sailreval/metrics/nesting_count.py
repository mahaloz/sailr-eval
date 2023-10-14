"""
Counts the amount of nesting for each if-statement
"""

def count_nesting_ifs(func_name, client, **kwargs):
    if client is None:
        return None

    return client.count_if_levels(func_name)