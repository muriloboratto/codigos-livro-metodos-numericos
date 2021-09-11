# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   gaussJacobi.py 
#
#  Purpose:
#   Implement the Gauss Jacobi Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python gaussJacobi.py 
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

print('Gass Jacobi Method')
print('k      x1     x2     x3 ')
print("%d  %.4f  %.4f  %.4f"%(k, x1, x2, x3))

for k in range(1, 1000):
    x1_new = 1.4  - 0.20*x2 - 0.10*x3    
    x2_new = 2.20 - 0.20*x1 - 0.20*x3
    x3_new = 0.80 - 0.20*x1 - 0.30*x2
    
    x = np.array([x1_new, x2_new, x3_new])
    dx = np.sqrt(np.dot(x-x_old, x-x_old))
    
    print("%d  %.4f  %.4f  %.4f"%(k, x1_new, x2_new, x3_new))
    
    x1 = x1_new
    x2 = x2_new
    x3 = x3_new
    
    if dx < epsilon:
        converged = True
        print('Converged!')
        break
        
    x_old = x

if not converged:
    print('Not converge!')

