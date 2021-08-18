#****************************************************************************80
#  Code: 
#   analytic_parabola.py 
#
#  Purpose:
#   Implement the analytics method for solver EDO in Python
#
#  Modified:
#   Aug 11 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
#   
#  How to Execute:
#    python analytic_parabola.py 
#   
#  Comments:
#
#*****************************************************************************


import numpy as np
import pylab as plt

def f(x, K):
  return x*x+K

a = -2
b =  2
num_points = 100
K  = 5.0
x  = np.linspace(a, b, num_points)

plt.plot(x, f(x, K), 'bo')
plt.xlabel('x')
plt.ylabel('y')
plt.show()
