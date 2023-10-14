def count_total_loc(func_name, client, **kwargs):
    if client is None:
        return None

    return client.get_func_loc(func_name)