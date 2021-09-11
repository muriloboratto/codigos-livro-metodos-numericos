# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   runger_kutta_exercise_7312.py 
#
#  Purpose:
#   Implement the Runger Kutta Method for solver EDO in Python
#   Exercise 7.3.1.2 - Book 'Métodos Numéricos e Computacionais Aplicados as Ciências e Engenharias'  
#
#  Modified:
#   Jul 25 2021 16:34 
#
#  Author:
#     Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python runger_kutta_exercise_7312.py 
#   
#  Comments:
#
#****************************************************************************

import numpy as np
import pylab as plt

# Defining the parameters of the function f(x,y)
f = lambda x, y: y*x - x*x*x

# Defining the parameters of the function derivate f'(x,y)
f_l = lambda x, y: y + (y-3)*x*x - x*x*x*x 

a = 0                        # Initial Range
b = 1.8                      # Final Range
h = 0.6                      # Step Pass
x = np.arange(a, b + h, h)   # Grid
y0 = 1                       # PIV

# Runger Kutta's Explicit Method
y = np.zeros(len(x)) 
y[0] = y0

for i in range(0, len(x) - 1):
    y[i + 1] = y[i] + f(x[i], y[i]) * h + ((h * h)/2) * f_l(x[i], y[i])
    print("%d   %f   %f"%(i, x[i], y[i]))

print("%d   %f   %f"%(i+1, x[i+1], y[i+1]))

plt.plot(x, y, 'bo--', label='Runger Kutta')
plt.plot(x, x*x-np.exp(0.5*x*x)+2, 'g', label='Exact')
plt.xlabel('x')
plt.ylabel('f(x,y)')
plt.show()
