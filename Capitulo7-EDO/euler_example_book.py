# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   euler_example_book.py 
#
#  Purpose:
#   Implement the Euler Method for solver EDO in Python
#   Example Euler Method - Book 'Métodos Numéricos e Computacionais Aplicados as Ciências e Engenharias'  
#
#  Modified:
#   Jul 25 2021 16:34 
#
#  Author:
#     Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python euler_example_book.py  
#   
#  Comments:
#
#****************************************************************************

import numpy as np
import pylab as plt

# Defining the parameters of the function f(x,y)
f = lambda x, y: -2 * x * x * x + y

a = 0                        # Initial range
b = 1.5                      # Final range
h = 0.5                      # Step pass
x = np.arange(a, b + h, h)   # Grid
y0 = 1                       # PIV

y = np.zeros(len(x)) 
y[0] = y0

# Euler's Explicit Method
for i in range(0, len(x) - 1):
    y[i + 1] = y[i] + f(x[i], y[i]) * h
    print("%d   %f   %f"%(i, x[i], y[i]))

print("%d   %f   %f"%(i+1, x[i+1], y[i+1]))

plt.plot(x, y, 'bo--', label='Euler')
plt.xlabel('x')
plt.ylabel('f(x,y)')
plt.show()
