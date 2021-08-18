#****************************************************************************80
#  Code: 
#   runger_kutta_example_book.py 
#
#  Purpose:
#   Implement the Euler Method for solver EDO in Python
#   Example Runger Kutta Method - Book 'Métodos Numéricos e Computacionais Aplicados as Ciências e Engenharias'  
#
#  Modified:
#   Jul 25 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
#   
#  How to Execute:
#    python runger_kutta_example_book.py
#   
#  Comments:
#
#****************************************************************************

import numpy as np
import pylab as plt

# Defining the parameters of the function f(x,y)
f = lambda x, y: x - y +2

# Defining the parameters of the function derivate f'(x,y)
f_l = lambda x, y: y - x - 1

a = 0                        # Initial range
b = 1                        # Final range
h = 0.1                      # Step pass
x = np.arange(a, b + h, h)   # Grid
y0 = 2                       # PIV

# Runger Kutta's Explicit Method
y = np.zeros(len(x)) 
y[0] = y0

for i in range(0, len(x) - 1):
    y[i + 1] = y[i] + f(x[i], y[i]) * h + ((h * h)/2) * f_l(x[i], y[i])
    print("%d   %f   %f"%(i, x[i], y[i]))

print("%d   %f   %f"%(i+1, x[i+1], y[i+1]))

plt.plot(x, y, 'bo--', label='Runger Kutta')
plt.xlabel('x')
plt.ylabel('f(x,y)')
plt.show()
