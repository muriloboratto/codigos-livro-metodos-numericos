#****************************************************************************80
#  Code: 
#   analytic_population.py 
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
#    python analytic_population.py
#   
#  Comments:
#
#*****************************************************************************

import numpy as np
import pylab as plt

def N(No, K, t):
  return No * np.exp(K*t)

a = 0
b = 20
num_points =40
No = 100
K  = 0.1
t  = np.linspace(a, b, num_points)

plt.plot(t, N(No, K, t), 'bo')
plt.xlabel('t')
plt.ylabel('N(t)')
plt.show()
