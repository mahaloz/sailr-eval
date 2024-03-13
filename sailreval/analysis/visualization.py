import textwrap
from typing import Dict, List

STAT_TYPES = ("sum", "mean", "median")


#
# Graphs
#

def plot_histogram(data1, data2, save_path="./histo_chart.png"):
    import matplotlib as mpl
    mpl.use('Agg')
    import matplotlib.pyplot as plt
    import numpy as np
    
    # Sample Data
    IDA = data1
    SAILR = data2
    # Calculate the unique elements and their counts for both lists
    values_IDA, counts_IDA = np.unique(IDA, return_counts=True)
    values_SAILR, counts_SAILR = np.unique(SAILR, return_counts=True)
    
    # Create dictionaries for both datasets
    dict_IDA = dict(zip(values_IDA, counts_IDA))
    dict_SAILR = dict(zip(values_SAILR, counts_SAILR))
    
    # Ensure every key in one dictionary exists in the other (even if it's zero)
    for key in dict_IDA.keys():
        dict_SAILR[key] = dict_SAILR.get(key, 0)
    
    for key in dict_SAILR.keys():
        dict_IDA[key] = dict_IDA.get(key, 0)
    
    # Sort the dictionaries by their keys for plotting
    dict_IDA = dict(sorted(dict_IDA.items()))
    dict_SAILR = dict(sorted(dict_SAILR.items()))
    
    # Calculate the difference in counts
    diff = [dict_SAILR[key] - dict_IDA[key] for key in dict_IDA.keys()]
    
    # Plot
    plt.bar(dict_IDA.keys(), diff, color=['red' if d < 0 else 'blue' for d in diff])
    plt.axhline(0, color='black',linewidth=0.8)
    plt.xlabel('CFGED Score')
    plt.ylabel('SAILR count - IDA count')
    plt.ylim(-60, 60)  # Adjusting the upper limit to +

    plt.title('Difference in frequencies between SAILR and IDA')

    plt.savefig(save_path)


def plot_diff_barchar(data_by_row: Dict[str, List], metric: str, decompilers: List, save_path="./diff_bar_chart.png"):
    import matplotlib as mpl
    mpl.use('Agg')
    import matplotlib.pyplot as plt
    import pandas as pd

    assert len(decompilers) == 2
    metric_data = data_by_row[metric]

    data = {
        'Function': range(len(metric_data[decompilers[0]])),
        decompilers[0]: metric_data[decompilers[0]],
        decompilers[1]: metric_data[decompilers[1]]
    }
    df = pd.DataFrame(data)
    df['Diff'] = df[decompilers[0]] - df[decompilers[1]]
    df['Diff'] = df['Diff'].where(df['Diff'] > 0)

    df = df.sort_values('Diff', ascending=False)
    df['Function'] = range(df['Diff'].size)
    plt.bar(df['Function'], df['Diff'], label=f'{decompilers[0]} - {decompilers[1]}')
    plt.xlabel('Function')
    plt.ylabel(metric)
    plt.savefig(save_path)


def plot_barchart(data_by_row: Dict[str, List], save_path="./bar_chart.png"):
    import matplotlib as mpl
    mpl.use('Agg')
    import matplotlib.pyplot as plt
    import pandas as pd
    data = {
        'Function': range(len(data_by_row["angr_sailr"])),
        'angr_phoenix': data_by_row["angr_phoenix"],
        'angr_sailr': data_by_row["angr_sailr"]
    }
    df = pd.DataFrame(data)

    # Step 3: Sort your data
    # Let's say we want to sort by the total of 'Value1' and 'Value2' in descending order
    df['Diff'] = df['angr_sailr'] - df['angr_phoenix']
    df = df.sort_values('Diff', ascending=False)
    df['Function'] = range(len(df['angr_phoenix']))
    plt.bar(df['Function'], df['Diff'], label='angr_sailr - angr_phoenix')

    # Set the x and y-axis labels
    plt.xlabel('Function')
    plt.ylabel('CFGED')

    # Set a title
    plt.title('CFGED Scores')

    plt.savefig(save_path)


def plot_box_plot(data_by_row: Dict[str, List], save_path="./boxplot.png"):
    import matplotlib as mpl
    mpl.use('Agg')
    import matplotlib.pyplot as plt
    plt.figure(figsize=(10, 6))  # Set the figure size
    plt.boxplot(data_by_row.values(), vert=False, widths=0.7)  # Plot the data

    # Set the y-axis labels
    plt.yticks([1, 2], data_by_row.keys())

    # Set the x-axis limits to give some margins
    plt.xlim([-50, 1450])  # You can adjust these numbers based on your data

    # Set the x-axis label
    plt.xlabel('Values')

    # Set a title
    plt.title('Boxplot of Data')

    plt.savefig(save_path)


#
# Markdown Table
#

def tablify_data_for_metrics(summary):
    first_dec = list(summary.keys())[0]
    all_metrics = list(summary[first_dec].keys())
    good_metrics = set()
    if "metadata" in summary:
        del summary["metadata"]
    for metric in all_metrics:
        raw_metric_name = "_".join(metric.split("_")[:-1])
        is_bad = False
        for stat_type in STAT_TYPES:
            if f"{raw_metric_name}_{stat_type}" not in all_metrics:
                is_bad = True
                break

        if not is_bad:
            good_metrics.add(raw_metric_name)

    row_by_metric = list()
    for metric in good_metrics:

        row = {"Metric": metric}
        for dec in summary.keys():
            data = []
            for stat_type in STAT_TYPES:
                data.append(summary[dec][f"{metric}_{stat_type}"])

            #row[dec] = str(tuple(data))
            row[dec] = "/".join([str(d) for d in data])

        row_by_metric.append(row)

    return row_by_metric


def tablify_data(summary, show_stats=False):
    table_summary = list()
    metadata_table = {}
    for dec, data in summary.items():

        row = {"Decompiler": dec}
        for metric_name, metric_data in data.items():
            row[metric_name] = metric_data

        if dec == "metadata":
            del row["Decompiler"]
            metadata_table = row
            continue

        table_summary.append(row)

    if show_stats:
        table_summary = tablify_data_for_metrics(summary)

    return table_summary, metadata_table


def save_data_as_markdown_table(summary, save_path="./summary.md", show_stats=False):
    def format_table(myDict, colList=None):
        """ Pretty print a list of dictionaries (myDict) as a dynamically sized table.
        If column names (colList) aren't specified, they will show in random order.
        Author: Thierry Husson - Use it as you want but don't blame me.
        """
        if not colList: colList = list(myDict[0].keys() if myDict else [])
        myList = [colList]  # 1st row = header
        for item in myDict: myList.append([str(item[col] if item[col] is not None else '') for col in colList])
        colSize = [max(map(len, col)) for col in zip(*myList)]
        formatStr = ' | '.join(["{{:<{}}}".format(i) for i in colSize])
        myList.insert(1, ['-' * i for i in colSize])  # Seperating line
        for item in myList: yield formatStr.format(*item)

    markdown_summary = ""
    for pkg_name, pkg_data in summary.items():
        table_summary, metadata_table = tablify_data(pkg_data, show_stats=show_stats)
        markdown_summary += f"### {pkg_name}\n" + f"\n".join(list(format_table(table_summary))) + "\n\n"

    markdown_metadata = "\n".join(list(format_table([metadata_table])))
    markdown_doc = textwrap.dedent(f"""\n\n# Evaluation Data
## Stats
{f"Layout: {STAT_TYPES}" if show_stats else ""}
{markdown_summary}
## Metadata

{markdown_metadata}""")

    with open(save_path, "w") as fp:
        fp.write(markdown_doc)

    return markdown_doc
