import numpy as np
import matplotlib.pyplot as plt
###################################################################
def seedLCG(initVal):
    global rand
    rand = initVal

def lcg(a,c,m):  # Linear congruential generator (LCG)
    global rand
    rand = (a*rand + c) % m
    return rand/float(m)

def my_rand(n,a,c,m):
    rand_num = np.zeros((n),float)
    for i in range(n):
        rand_num[i] =  lcg(a,c,m)
    return rand_num

### MAIN PROGRAM #################################################
# very simple set of parameters for LCG
a1  = 106
c1  = 1283
m1  = 6075
# other set of parameters for LCG
a2  = 137
c2  = 0
m2  = 2**17
# Park-Miller set of parameters for LCG
a3 = 7**5
c3 = 0
m3 = 2**31 - 1

seedLCG(123)

n  = 10**4

x1 = my_rand(n,a1,c1,m1);y1 = my_rand(n,a1,c1,m1)
x2 = my_rand(n,a2,c2,m2);y2 = my_rand(n,a2,c2,m2)
x3 = my_rand(n,a3,c3,m3);y3 = my_rand(n,a3,c3,m3)
x4 = np.random.rand(n);  y4 = np.random.rand(n)

# plot spectral test
f,ax = plt.subplots(2,2,sharex=True,sharey=True,figsize=(10,10))
ax[0,0].plot(x1,y1,'.',markersize=1.0)
ax[1,0].plot(x2,y2,'.',markersize=1.0)
ax[0,1].plot(x3,y3,'.',markersize=1.0)
ax[1,1].plot(x4,y4,'.',markersize=1.0)

ax[0,0].set_title('LCG: a = 106, c=1283, m = 6075')
ax[1,0].set_title('LCG: a = 137, c=0, m = 2**17')
ax[0,1].set_title('LCG: a = 7**5, c=0, m = 2**31-1')
ax[1,1].set_title('Python: Mersenne Twister generator')
ax[0,0].set_xlim(0,1)
ax[0,0].set_ylim(0,1)

plt.savefig("LCG_spectral_test.pdf")
plt.show()
