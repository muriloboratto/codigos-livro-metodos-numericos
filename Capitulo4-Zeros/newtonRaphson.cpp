/****************************************************************************80
*  Code: 
*   newtonRaphson.cpp 
*
*  Purpose:
*    Implements de C/C++ code  with the Newton-Raphson method for finding roots.
*
*  Modified:
*   Oct 27 2008 09:30 
*
*  Author:
*    Murilo Do Carmo Boratto [muriloboratto@uneb.br]
*
*  Compile:
*    g++ newtonc++.cpp -o objeto
*   
*  Execute:
*    ./objeto  
*
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <complex>

using namespace std;

template <class T1>
 int newton(T1 &x, T1 (&f)(T1), T1 (&fdiv)(T1),int max_loop, const double accuracy)
 {
    T1 term;
    int i=1;
    cout << "i" << "\t" << "x" << " " <<"\t\t\t  " << "f(x)" <<""<< "\t\t\t" << "f'(x)" << "" << "\n";
    cout << "------------------------------------------------------------------------\n";   
    
    
    do
    {
    
     term = (f)(x) / (fdiv)(x);
     x = x - term;  
     cout << "" << i++ << "\t" << fixed << x <<"\t\t" << " " <<(f)(x) << "\t\t" << (fdiv)(x) << "\n";
    
    if(abs((f)(x))<= accuracy )
      break;
    
    }while ((abs(term / x) > accuracy) && (--max_loop));
    
    return max_loop;
 
 }/*newton*/

//----------------------------------------------------------------------------//
                                               
/*1*/
double func_1(double x){return x*x - 25.0;}                                                                                  
double fdiv_1(double x){return 2.0 * x;}                           
  
/*2*/  
double func_2(double x){return 2*x*x*x - 4*x*x - 22*x + 24 ;}      
double fdiv_2(double x){return 6*x*x - 8*x - 22;}                       

/*3*/  
double func_3(double x){return x*x*x + 2*x - 1;}      
double fdiv_3(double x){return 3*x*x + 2;}                       

/*4*/  
double func_4(double x){return x*exp(x) - 1;}      
double fdiv_4(double x){return exp(x)*(1 + x);}             

/*5*/  
double func_5(double x){return x*x*(x*x - 1);}      
double fdiv_5(double x){return 4*x*x*x -2*x;}             

/*6*/  
double func_6(double x){return pow(2,x) - x*x;}      
double fdiv_6(double x){return log(2)*(pow(2,x)) - 2*x;}              

//----------------------------------------------------------------------------//

int main(void)
{

    /*1*/
    cout << "\n  [ f(x)  = x^2 - 25 ]";
    cout << "\n  [ f'(x) = 2 * x  ]\n\n";
    double x = 1.0;                                          
    if(newton(x, func_1, fdiv_1, 1000, 0.001))
        cout << "\n   Root  x = " << x << " .:. f(x) = " << func_1(x);
           else  
               cout << "\n  Root Calculation Failure ";

    
    /*2*
    cout << "\n [ f(x)  = 2x^3 - 4x^2 - 22x + 24 ]";
    cout << "\n [ f'(x) = 6x^2 - 8x - 22 ]\n\n";
    double x = 5.0;                                          
    if(newton(x, func_2, fdiv_2, 1000, 0.001))
         cout << "\n    Root  x = " << x << " .:. f(x) = " << func_2(x);
            else  
               cout << "\n  Root Calculation Failure ";
   
    
    /*3*
    cout << "\n [ f(x)  = x^3 + 2x - 1 ]";
    cout << "\n [ f'(x) = 3x^2 + 2 ]\n\n";
    double x = .5;                                          
    if(newton(x, func_3, fdiv_3, 1000, 0.002))
         cout << "\n    Root  x = " << x << " .:. f(x) = " << func_3(x);
            else  
                cout << "\n  Root Calculation Failure ";
 
 
   /*4*
    cout << "\n [ f(x)  = x*e^x - 1 ]";
    cout << "\n [ f'(x) = e^x*(1+x)]\n\n";
    double x = 1.0;                                          
    if(newton(x, func_4, fdiv_4, 1000, 0.01))
         cout << "\n    Root  x = " << x << " .:. f(x) = " << func_4(x);
            else  
                cout << "\n  Root Calculation Failure ";
 
     
   /*5*
    cout << "\n [ f(x)  =  x^2 *(x^2 - 1)]";
    cout << "\n [ f'(x) =  4x^3 -2x ]\n\n";
    double x = 2;                                          
    if(newton(x, func_5, fdiv_5, 1000, 0.002))
         cout << "\n    Root  x = " << x << " .:. f(x) = " << func_5(x);
            else  
               cout << "\n  Root Calculation Failure ";
     
     
     
    /*6*
    cout << "\n [ f(x)  =  2^x - x^2]";
    cout << "\n [ f'(x) =  (ln 2)*(2^x) - 2x ]\n\n";
    double x = -.7;                                          
    if(newton(x, func_6, fdiv_6, 1000, 0.001))
         cout << "\n    Root  x = " << x << " .:. f(x) = " << func_6(x);
            else  
               cout << "\n  Root Calculation Failure ";
        
   
    */
    
    cin.get();
    
    return 0;

}/*main*/

