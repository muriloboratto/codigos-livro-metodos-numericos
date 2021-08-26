# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   bisection.py 
#
#  Purpose:
#   Implement the Bisection Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python bisection.py 
#   
#*****************************************************************************

from math import *

def f(x):
    return x * x * x - x - 1

# Initial interval: assume f(a)<0 and f(b)>0
a=1
b=2
k=0

print(' k\ta\t\tb\t\tc\t\tDelta')

# Bisection search
while b-a>0.02:
    c=0.5*(b+a)
    k=k+1
    print('%2d\t%4f\t%4f\t%4f\t%4f'%(k, a, b, c, b-a))
    if f(c)<0: a=c
    else: b=c

print('\nRoot %4f'%((0.5*(a+b))))