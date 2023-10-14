def count_total_gotos(func_name, client, **kwargs):
    if client is None:
        return None

    if func_name not in client.functions:
        return None

    return client.count_gotos(func_name)
