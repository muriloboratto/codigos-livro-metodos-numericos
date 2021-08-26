# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   lagrange.py 
#
#  Purpose:
#   Implement the Lagrange Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python lagrange.py 
#
#*****************************************************************************

import numpy as np
from numpy.polynomial.polynomial import Polynomial
import pylab as plt
from scipy.interpolate import lagrange

x = [0, 1, 3]
y = [-5, 1, 25]

f = lagrange(x, y)

print(Polynomial(f).coef)

x_new = np.arange(0, 3.1, 0.1)

fig = plt.figure(figsize = (10,8))
plt.plot(x_new, f(x_new), 'b', x, y, 'ro')
plt.title('Lagrange Polynomial')
plt.grid()
plt.xlabel('x')
plt.ylabel('y')
plt.show()
