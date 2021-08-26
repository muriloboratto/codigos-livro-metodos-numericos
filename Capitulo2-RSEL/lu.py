# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   lu.py 
#
#  Purpose:
#   Implement the LU factorization in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python lu.py 
#
#*****************************************************************************


import pprint
import scipy
import scipy.linalg   # SciPy Linear Algebra Library

A = scipy.array([ [8,  2, 9 ], 
	              [4,  9, 4 ], 
	              [6,  7, 9 ] ])

P, L, U = scipy.linalg.lu(A)

print "A:"
pprint.pprint(A)

print "L:"
pprint.pprint(L)

print "U:"
pprint.pprint(U)