import numpy as np
import matplotlib.pyplot as plt

_array = np.loadtxt('3.txt', skiprows=1)
t,v,x = _array[:,0],_array[:,2],_array[:,1]

plt.figure(1)
plt.plot(t, v * v + x * x - 1)
plt.show()