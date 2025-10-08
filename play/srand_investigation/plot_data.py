#!/usr/bin/env python3

import matplotlib.pyplot as plt
import numpy as np

data = []

with open("data.txt", mode="r") as f:
    for line in f:
        data.append(int(line))

counts, bins = np.histogram(data)

# changing the style of the histogram bars just to make it
# very clear where the boundaries of the bins are:
style = {'facecolor': 'none', 'edgecolor': 'C0', 'linewidth': 3}
# plt.hist(data, **style, zorder=2)
plt.hist(bins[:-1], bins, weights=counts, align='left', **style)
plt.grid(linestyle='--', zorder=1)
plt.xticks([x for x in range(1, 11)])
plt.show()
