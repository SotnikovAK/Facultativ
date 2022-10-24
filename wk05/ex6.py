from symbol import parameters
import numpy as np
import json

class state:
    def __init__(self, x, v, w):
        self.x = x
        self.v = v
        self.w = w
    def __add__(self, o):
        return state (self.x + o.x, self.v + o.v, self.w)
    def __mul__(self, a):
        return state (self.x * a.x, self.v * a.v, self.w)
    def print(self):
        print(' ( '+str(self.x) + ' , '+str(self.v) + ' ,  ' + str(self.w) + ' ) ')

def move_(y, x):
    return state (y.v, -y.w ** 2 * x, y.w)

class Solver:
    def __init__(self, model, w, x0, v0, L, h):
        self.w = w
        self.x0 = x0
        self.v0 = v0
        self.L = L
        self.h = h

        self.N = int(L/h)
        self.model = model

        self.data = np.zeros(self.N, dtype=state)
        self.data[0] = state(x0, v0 , w)
        self.i = 0

    def add_step(self):
        if (self.i + 1 < self.N):
            y = self.data[self.i]
            if (self.model == 'Heun'):

                k1 = move_(y, y.x)
                k2 = move_(y + k1 * state(self.h,self.h,0), y.x + self.h * k1.x)
                self.data[self.i + 1] = y + (k1 + k2) * state(0.5*self.h,0.5*self.h,0)

            elif (self.model == 'Euler'):

                self.data[self.i + 1] = y + move_(y, y.x) * state(self.h,self.h,0)

            elif (self.model == 'RK45'):

                k1 = move_(y, y.x)
                k2 = move_(y + k1 * state(0.5*self.h,0.5*self.h,0), y.x + 0.5 * self.h)
                k3 = move_(y + k2 * state(0.5*self.h,0.5*self.h,0), y.x + 0.5 * self.h)
                k4 = move_(y + k3 * state(0.5*self.h,0.5*self.h,0), y.x + self.h)

                self.data[self.i + 1] = y + (k1 + k2*state(2,2,0) + k3*state(2,2,0) + k4) * state(self.h/6,self.h/6,0) 
            
            self.i += 1

    def write_data(self):
        print('Results:')
        for v in self.data:
            print(str(v.x) + ' , '+str(v.v) + ' , '+str(self.w) + ' , ' + str(self.L) + ' , ' + str(self.h))

    def solve(self):
        for i in range(self.N):
            self.add_step()  

read = open('config_file.json', 'r')
A = json.load(read)
read.close()

N = len(A['entries'])
parameters_ = np.zeros(N, dtype = Solver)

for i in range(N):
    parameters_[i] = Solver (A['entries'][i]['model'], A['entries'][i]['omega'], A['entries'][i]['initial coordinate'], A['entries'][i]['initial velocity'], A['entries'][i]['modeling interspace'], A['entries'][i]['step of modeling'])

for i in range(N):
    parameters_[i].solve()
    parameters_[i].write_data()