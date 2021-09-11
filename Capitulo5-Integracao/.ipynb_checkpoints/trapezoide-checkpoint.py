# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   trapezoide.py 
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
#    python trapezoide.py 
#   
#*****************************************************************************

import numpy as np
import matplotlib.pyplot as plt

def trapz(f, a, b, N):
    x = np.linspace(a, b, N+1) 
    y = f(x)
    y_right = y[1:] 
    y_left = y[:-1] 
    dx = (b - a)/N
    T = (dx/2) * np.sum(y_right + y_left)
    return T

f = lambda x : (1 + x**2)**(-1/2)
a = 0 
b = 4 
N = 9

x = np.linspace(a, b, N+1)
y = f(x)

T = trapz(f,a,b,N)
print("Trapezoide Integral: ", T)

#Plot
X = np.linspace(a, b, 100)
Y = f(X)
plt.plot(X,Y)

for i in range(N):
    xs = [x[i], x[i], x[i+1], x[i+1]]
    ys = [0, f(x[i]), f(x[i+1]), 0]
    plt.fill(xs, ys,'b',edgecolor='b',alpha=0.2)

plt.title('Trapezoid, N = {}'.format(N))
plt.show()
