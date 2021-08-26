import numpy as np

def secant(f, x0, x1, tol, max_iterations):
    init_x0 = x0
    init_x1 = x1

    fx0 = f(x0)
    fx1 = f(x1)

    print('%d\t%4f\t%4f'%(0, x0, fx0))
    print('%d\t%4f\t%4f'%(1, x1, fx1))
    i = 2
    for _ in range(max_iterations):
        if abs(fx1) < tol:
            return x1

        x2 = (x0 * fx1 - x1 * fx0) / (fx1 - fx0)

        print('%d\t%4f\t%4f'%(i, x2, fx0))
        i = i + 1
        x0,  x1  = x1,  x2
        fx0, fx1 = fx1, f(x2)

   
f = lambda x: x * x * x - x - 1 

print('\nRoot  %f' % (secant(f, 1.5, 1.7, 0.002, 100)))   