import numpy as np
import matplotlib.pyplot as plt

_array = np.loadtxt('4.txt', skiprows=1)
t,v,x = _array[:,0],_array[:,2],_array[:,1]

X = np.cos(t)
plt.figure(2)

plt.plot(t, v * v + x * x - 1)
#plt.plot(t,X)
plt.show()