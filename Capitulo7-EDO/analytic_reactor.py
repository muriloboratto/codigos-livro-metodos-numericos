# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   analytic_reactor.py 
#
#  Purpose:
#   Implement the analytics method for solver EDO in Python
#
#  Modified:
#   Jul 25 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
#   
#  How to Execute:
#    python analytic_reactor.py
#   
#  Comments:
#
#****************************************************************************

import numpy as np
import pylab as plt

def f(t, R, Fe, A):
  return R * Fe * (1-np.exp(-t/(R*A)))

a = 0
b = 10
num_points = 1000

R  = 1.0
A  = 2.0;
Fe = 10.0;  

t  = np.linspace(a, b, num_points)

plt.plot(t, f(t, R, Fe, A), 'bo')
plt.xlabel('time (h)')
plt.ylabel('height (m)')
plt.show()
