import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import time
from tqdm import tqdm

# RANDU

def ibm_randu_init(seed):
    def rand():
        rand.seed = (65539*rand.seed) & 0x7fffffff
        return rand.seed
    rand.seed = seed
    return rand

ibm_randu = ibm_randu_init(seed=1)

# Figure + Progress Bar

value_range = round(5000/3)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

for i in tqdm(range(value_range)):
    xs = ibm_randu()
    ys = ibm_randu()
    zs = ibm_randu()
    if i < 10:
        print("\r[%s]\t[%s]\t[%s]" % (xs,ys,zs))

    ax.scatter(xs, ys, zs, c='b')

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()


