# -*- coding: utf-8 -*-
#****************************************************************************80
#  Code: 
#   newton.py 
#
#  Purpose:
#   Implement the Newton Method in Python
#
#  Modified:
#   Aug 24 2021 16:34 
#
#  Author:
#    Murilo Do Carmo Boratto < muriloboratto 'at' uneb.br >  
#   
#  How to Execute:
#    python newton.py 
#
#  Comment
#    - Install module pandas with anaconda in command line, i.e:
#        $> pip install pandas 
#   
#*****************************************************************************

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np


def newton_interpolation(x, y, xi):  
    n = len(x)                                         #length/number of datapoints
    fdd = [[None for x in range(n)] for x in range(n)] #divided difference initialization
    yint = [None for x in range(n)]                    #f(X) values at different degrees
    ea = [None for x in range(n)]                      #error value
    
    for i in range(n):                                 #finding divided difference
        fdd[i][0] = y[i]
    for j in range(1,n):
        for i in range(n-j):
            fdd[i][j] = (fdd[i+1][j-1] - fdd[i][j-1])/(x[i+j]-x[i])
    
    fdd_table = pd.DataFrame(fdd)                       #just printing dd here
    print(fdd_table)
    
    xterm = 1                                           #interpolating xi
    yint[0] = fdd[0][0]
    for order in range(1, n):
        xterm = xterm * (xi - x[order-1])
        yint2 = yint[order-1] + fdd[0][order]*xterm
        ea[order-1] = yint2 - yint[order-1]
        yint[order] = yint2
    
    return map(lambda yy, ee : [yy, ee], yint, ea)     #returning a map for pandas dataframe


x = [0,  1,  3,   4,   6]
y = [3,  0,  18,  63,  285]

a  = newton_interpolation(x, y, 2)
df = pd.DataFrame(a)

