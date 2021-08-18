/****************************************************************************80
*  Code: 
*   bisection.c 
*
*  Purpose:
*   Implements C code with the Bisection method for finding roots.
*
*  Modified:
*   Jan 20 2018 12:09 
*
*  Author:
*    Murilo Do Carmo Boratto [muriloboratto@uneb.br]
*
*  How to compile:
*    gcc bisection.c -o object
*   
*  How to execute:
*
*      -a = inicial range
*      -b = final range
*      -t = tolerance
*      -e = number of the equation     
*
*      ./object -a 2 -b 3 -t 0.002 -e 1 
*
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define USAGE "bisection [ -a float -b float -t float -e int ]"

#define TOLERANCE .0001
#define LEFT 1.0
#define RIGHT 10.0
#define MAXPASS 1000

#ifndef HAVEF
int equation;

double f(double x){

     double y;

     switch(equation){      
       case 0: y = x * x + log(x);        break;
       case 1: y = x * log10(x) - 1;      break;
       case 2: y = x * x + log(x);        break;
       case 3: y = x * x * x - x - 1;     break;   
       case 4: y = x * x - 3;             break; 
       case 5: y = x * x * x - 10;        break;
     }	

     return y;
}

#else
 extern double f(double);
#endif

#ifndef NOMAIN
int main(int argc, char **argv){
	
   double tolerance = TOLERANCE;
   double a = LEFT;
   double b = RIGHT;
   double c,d,e,mid;
   int j=0,n=1;

   while(++j < argc){
		
		if(argv[j][0] == '-')
		
		switch(argv[j][1]){ 
        case 'a':
				case 'A':
					if(j+1 >= argc)
                    {
						fprintf(stderr,"%s\n",USAGE);
						exit(1);
					}
					a = atof(argv[j+1]);
					j++;
					continue;
			
          case 'b':
				  case 'B':
					if(j+1 >= argc)
                    {
						fprintf(stderr,"%s\n",USAGE);
						exit(1);
					}
					b = atof(argv[j+1]);
					j++;
					continue;
				
			    case 't':
				  case 'T':
					if(j+1 >= argc){
						fprintf(stderr,"%s\n",USAGE);
						exit(1);
					}
					tolerance = atof(argv[j+1]);
					if(tolerance <= 0.0){
						fprintf(stderr,"Tolerance needs to be positive.\n");
						exit(1);
					}
					j++;
					continue;	
				 
          case 'e':
				  case 'E':
					if(j+1 >= argc){
						fprintf(stderr,"%s\n",USAGE);
						exit(1);
					}
					equation = atoi(argv[j+1]);
					j++;
					continue;	
				    
    
    			default:
					fprintf(stderr,"No option chosen %s\n", argv[j]);
					exit(1);
      }
	
    }/*while*/


	if( b < a )
    {
	 fprintf(stderr,"Error: Initial range.\n");	
   	 exit(1);
	}
	
    c = f(a); 
    d = f(b);
	
    if(((c>0.0)&&(d>0.0))||((c<0.0)&&(d<0.0)))
    {
	 fprintf(stderr,"Error: Signal of the range.\n");
	 exit(1);
	}	
		
    switch(equation){
       case 0:  printf("\n\n[Bisection] Equation: x^2 + ln(x) \n\n");    break;
       case 1:  printf("\n\n[Bisection] Equation: x*log(x) - 1\n\n");    break;
       case 2:  printf("\n\n[Bisection] Equation: x^2 + log(x)\n\n");    break;
       case 3:  printf("\n\n[Bisection] Equation: x^3 - x - 1 \n\n");    break;
       case 4:  printf("\n\n[Bisection] Equation: x^2 - 3     \n\n");    break;
       case 5:  printf("\n\n[Bisection] Equation: x^3 - 10    \n\n");    break;
    } 
		
    while(1){
		mid = (a+b)/2.0;
		e = f(mid);
		
		printf("%d f[%10.8f, %10.8f]  =  [%10.8f, %10.8f]\n", n, a, b, c, d);
		
      if(fabs(e) < tolerance){
		  printf("\n {x = %10.8f} Tolerance %9.8f.\n\n", mid, tolerance);
		  exit(0);
		}
		
		
			if(c > 0.0 && e < 0.0) 
				b = mid;
		    	else 
		    		a = mid;
		
     if(c < 0.0 && e > 0.0)
			   	b = mid;
		    	    else 
		    	    	a = mid;

     c = f(a); 
     d = f(b);
		
     n++;
		
     if(n > MAXPASS)
       exit(1);     
	
    }

	return 0;

}/*main*/

#endif

double bisection(double a, double b, double(*f)(double),double tolerance){

	double mid, c, d, e;

	c = f(a); 
	d = f(b);
	
	while(1){

  mid = (a+b)/2.0;
	e = f(mid);
	
	if(fabs(e) < tolerance)
       break;

	if(c > 0.0 && e < 0.0)
	  	b = mid;
		else 
		 	a = mid;

	 if(c < 0.0 && e > 0.0)
		 	 b = mid;
		 else 
			 a = mid;

	  c = f(a); 
	  d = f(b);
	}
	
	return mid;

}
