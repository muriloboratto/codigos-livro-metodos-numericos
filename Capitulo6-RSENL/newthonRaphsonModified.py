# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   newthonRaphsonModified.py 
#
#  Purpose:
#   Implement the Newthon Raphson Modified in Python for nonlinear equations
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python newthonRaphsonModified.py 
#   
#*****************************************************************************

import numpy as np

def jacobian_exercise_6_1_a(xy):
    x, y = xy
    return [[1,    2],
            [6*x,  1]]

def function_exercise_6_1_a(xy):
    x, y = xy
    return [x + 2*y - 3, 3*x**2 + y - 7]


def newtonRapshonModified(f, jacobian, x_init):
    max_iter = 50
    epsilon = 0.1

    x_last = x_init

    for k in range(max_iter):
        # Solve J(xn)*( xn+1 - xn ) = -F(xn)
        J = np.array(jacobian(x_last))
        F = np.array(f(x_last))

        diff = np.linalg.solve( J, -F )
        x_last = x_last + diff

        # Stop condition
        if np.linalg.norm(diff) < epsilon:
            print('Iterations =', k )
            break

    else: 
        print('not converged')

    return x_last

print('solution exercise 6.1 a):', newtonRapshonModified(function_exercise_6_1_a, jacobian_exercise_6_1_a, [0.5,0.5]))
