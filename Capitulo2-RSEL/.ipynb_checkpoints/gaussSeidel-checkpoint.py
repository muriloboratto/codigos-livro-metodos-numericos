# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   gaussSeidel.py 
#
#  Purpose:
#   Implement the Gauss Seidel Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python gaussSeidel.py 
#
#*****************************************************************************

import numpy as np

x1 = 0
x2 = 0
x3 = 0
k  = 0
epsilon = 0.01
converged = False

x_old = np.array([x1, x2, x3])

print('Gass Seidel Method')
print('k      x1     x2     x3 ')
print("%d  %.4f  %.4f  %.4f"%(k, x1, x2, x3))

for k in range(1, 1000):

    x1 = 1.4  - 0.20*x2 - 0.10*x3    
    x2 = 2.20 - 0.20*x1 - 0.20*x3
    x3 = 0.80 - 0.20*x1 - 0.30*x2
    
    x = np.array([x1, x2, x3])
    dx = np.sqrt(np.dot(x-x_old, x-x_old))
    
    print("%d  %.4f  %.4f  %.4f"%(k, x1, x2, x3))

    if dx < epsilon:
        converged = True
        print('Converged!')
        break
        
    x_old = x

if not converged:
    print('Not converge!')