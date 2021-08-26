# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   fixPoint.py 
#
#  Purpose:
#   Implement the Fix Point Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python fixPoint.py 
#   
#*****************************************************************************

import numpy as np

def fixPoint(f, g, x0, tol):
    if abs(f(x0)) < tol:
        return x0
    else:
        print('%4f\t%4f'%(g(x0), f(x0)))
        return fixPoint(f, g, g(x0), tol)

f = lambda x: x * x * x - x - 1 
g = lambda x: (1 + x)**(1. / 3) 

print(' x\t\tDelta')
print('\nRoot  %f' % (fixPoint(f, g, 1, 0.02)))

