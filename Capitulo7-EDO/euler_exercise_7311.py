#****************************************************************************80
#  Code: 
#   euler_exercise_7311.py 
#
#  Purpose:
#   Implement the Euler Method for solver EDO in Python
#   Exercise 7.3.1.1 - Book 'Métodos Numéricos e Computacionais Aplicados as Ciências e Engenharias'  
#
#  Modified:
#   Jul 25 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
#   
#  How to Execute:
#    python euler_exercise_7311.py  
#   
#  Comments:
#
#****************************************************************************

import numpy as np
import pylab as plt

# Defining the parameters of the function f(x,y)
f = lambda x, y: -1.2 * y + 7 * np.exp(-0.3 * x)

a = 0                        # Initial range
b = 2                        # Final range
h = 0.5                      # Step pass
x = np.arange(a, b + h, h)   # Grid
y0 = 3                       # PIV

# Euler's Explicit Method
y = np.zeros(len(x)) 
y[0] = y0

for i in range(0, len(x) - 1):
    y[i + 1] = y[i] + f(x[i], y[i]) * h
    print("%d   %f   %f"%(i, x[i], y[i]))

print("%d   %f   %f"%(i+1, x[i+1], y[i+1]))

plt.plot(x, y, 'bo--', label='Euler')
plt.plot(x, (70/9)*np.exp(-0.3*x)-(43/9)*np.exp(-1.2*x), 'g', label='Exact')
plt.xlabel('x')
plt.ylabel('f(x,y)')
plt.show()
