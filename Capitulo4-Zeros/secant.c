/****************************************************************************80
*  Code: 
*   secant.c 
*
*  Purpose:
*   Implements de C code with the Secant method for finding roots.
*
*  Modified:
*   Jan 20 2018 22:18 
*
*  Author:
*    Murilo Do Carmo Boratto [muriloboratto@uneb.br]
*
*  Compile:
*    gcc secant.c -o objeto
*   
*  Execute:
*    ./objeto  
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
  
double f(double x){

return pow(x,3) - x - 1;
//    return pow(x,2) + x - 6;
//    return pow(x,3) - 2*pow(x,2)-5;
//    return x - cos(x);
//    return sqrt(x) - 5*exp(-x);
//    return pow(x,3) - .5;


}/*f*/
  
double SecantMethod(double xn_1, double xn, double e, int m){

   int n = 2;
   double d;
    
   printf("  i              x                f(x)     \n");
   printf("-------------------------------------------\n");   
   
   printf("  %d          %1.6f           %1.6f\n", 0, xn_1, f(xn_1));
   printf("  %d          %1.6f           %1.6f\n", 1, xn,   f(xn));
    
    do{
        d = (xn - xn_1) / (f(xn) - f(xn_1)) * f(xn); 
        xn_1 = xn;
        xn = xn - d;
   
        printf("  %d          %1.6f           %1.6f\n", n++, xn, f(xn));
             
    }while ((fabs(f(xn)) > e) && (--m));
    
    return xn;

}/*SecantMethod*/
  
int main(int argc, char **argv){
        
    printf("\n\n    Root  x = %1.6f\n\n", SecantMethod(1, 2, 0.002, 10000));  
    // printf("\n\n    Root  x = %1.6f\n\n", SecantMethod(1.5, 1.7, 0.001, 10000));
    // printf("\n\n    Root  x = %1.6f\n\n", SecantMethod(1.5, 2.5, 0.001, 10000));
    // printf("\n\n    Root  x = %1.6f\n\n", SecantMethod(0, 1, 0.001, 10000));
    // printf("\n\n    Root  x = %1.6f\n\n", SecantMethod(1.4, 1.5, 0.001, 10000)); 
    // printf("\n\n    Root  x = %1.6f\n\n", SecantMethod(0, 1, 0.001, 10000));
  
    return 0;

}/*main*/

