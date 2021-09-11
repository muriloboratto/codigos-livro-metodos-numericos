# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   lu.py 
#
#  Purpose:
#   Implement the LU factorization in Python
#
#  Modified:
#   Set 02 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python lu.py 
#
#*****************************************************************************

import pprint
import numpy as np
import scipy.linalg as linalg 

A = np.array([ [1,   2,  -1 ], 
               [2,   3,  -2 ], 
               [1,  -2,   1] ])

B = np.array([2, 3, 0])

LU = linalg.lu_factor(A) 

x = linalg.lu_solve(LU, B) 
print(x)

