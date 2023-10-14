from collections import Counter, OrderedDict

def count_func_calls(func_name, client, **kwargs):
    if client is None:
        return None

    if func_name not in client.functions:
        return None

    func_calls = client.func_calls_in_func(func_name)
    if not func_calls:
        return {"__empty__": 0}

    counter = Counter(func_calls)
    output = OrderedDict(sorted(counter.items()))
    output = {k:v for k,v in output.items()}
    return output


