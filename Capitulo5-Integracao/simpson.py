# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   simpson.py 
#
#  Purpose:
#   Implement the Simpson Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python simpson.py 
#   
#*****************************************************************************

import scipy.integrate as spi
import numpy as np
import matplotlib.pyplot as plt

N = 6 
a = 0 
b = 3

f = lambda x : x*np.exp(x)+1
x = np.linspace(a, b, N+1)
y = f(x)

I_s = spi.simps(y,x)
print("Simpson Integral: ", I_s)

X = np.linspace(a, b, 100)
Y = f(X)
plt.plot(X,Y)

for i in range(N):
    xs = [x[i], x[i], x[i+1], x[i+1]]
    ys = [0, f(x[i]), f(x[i+1]), 0]
    plt.fill(xs, ys,'b',edgecolor='b',alpha=0.2)

plt.title('Simpson, N = {}'.format(N))
plt.show()