# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   newthonRapshon.py 
#
#  Purpose:
#   Implement the Newthon Rapshon Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python newthonRapshon.py 
#   
#*****************************************************************************

import numpy as np

def newthonRapshon(f, df, x0, tol):
    if abs(f(x0)) < tol:
        return x0
    else:
        print('%4f\t%4f'%(x0 - f(x0)/df(x0), f(x0)))
        return newthonRapshon(f, df, x0 - f(x0)/df(x0), tol)

f = lambda x: x**2 - 2
f_derivate = lambda x: 2*x

print(' x\t\tDelta')
print('\nRoot  %f' % (newthonRapshon(f, f_derivate, 1.5, 1e-6)))


