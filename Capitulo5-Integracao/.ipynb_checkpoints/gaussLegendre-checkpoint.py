# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   gaussLegendre.py 
#
#  Purpose:
#   Implement the Gauss Legendre Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python gaussLegendre.py 
#   
#*****************************************************************************

import numpy as np
import matplotlib.pyplot as plt

def gaussLegendre(f, a, b, E, A):
    #Plot
    N = 2
    X = np.linspace(a, b, 100)
    Y = f(X)
    plt.plot(X,Y)
    
    x = np.zeros(3)
    for i in range(3):
        x[i] = (b+a)/2 + (b-a)/2 * t[i]
        
    for i in range(N):  
        xs = [x[i], x[i], x[i+1], x[i+1]]
        ys = [0, f(x[i]), f(x[i+1]), 0]
        plt.fill(xs, ys,'b',edgecolor='b',alpha=0.2)

    plt.title('Gauss, N = {}'.format(N))
    plt.show()

    return (b-a)/2 * (P[0]*f(x[0]) + P[1]*f(x[1]) + P[2]*f(x[2]))

# coefficients for 2 subintervals

P = np.array([0.555556, 0.888889, 0.555556])  #Po = 5/9            P1 = 8/9     P2 = 5/9
t = np.array([-0.774597, 0.000000, 0.774597]) #t0 = -(3/5)**(-1/2) t1 = 0       t2 = +(3/5)**(-1/2)   

f = lambda x: 3 * np.exp(x)
a = 1 
b = 3

print("Gaussian Integral: ", gaussLegendre(f, a, b, t, P))
