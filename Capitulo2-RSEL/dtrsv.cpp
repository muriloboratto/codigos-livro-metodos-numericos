/*%****************************************************************************80
%  Code: 
%   dtrsv.cpp
%
%  Purpose:
%   Solver a Lower Triangular System
%  
%  Modified:
%   Jan 28 2010 11:00 
%
%  Author:
%    Murilo Do Carmo Boratto [muriloboratto@uneb.br]
%
% Compile:
%     g++ dtrsv.cpp -o objeto
%
%  Execute: 
%     ./objeto <size> <block size>
%     ./objeto    8      2
%
%****************************************************************************80*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int mydgemv_(char *trans, int *m, int *n, double *alpha, double *a, int *lda, double *x, int *incx,double *beta, double *y, int *incy)
{
/* System generated locals */
    int a_dim1, a_offset, i__1, i__2;

/* Local variables */
    static int info;
    static double temp;
    static int lenx, leny, i, j;
    static int ix, iy, jx, jy, kx, ky;
  
    #define X(I) x[(I)-1]
    #define Y(I) y[(I)-1]
    #define A(I,J) a[(I)-1 + ((J)-1)* ( *lda)]

    info = 0;
    
/*Set  LENX  and  LENY, the lengths of the vectors x and y, and set up the start points in  X  and  Y. */

    if (trans== "N") {
	     lenx = *n;
	     leny = *m;
    } else {
	       lenx = *m;
	       leny = *n;
    }
    
    if (*incx > 0) {
	      kx = 1;
    } else {
	       kx = 1 - (lenx - 1) * *incx;
    }
    
    if (*incy > 0) {
	      ky = 1;
    } else {
	       ky = 1 - (leny - 1) * *incy;
    }

/* Start the operations. In this version the elements of A are accessed sequentially with one pass through A.   
   First form  y := beta*y. */

    if (*beta != 1.) {
    	if (*incy == 1) {
	      if (*beta == 0.) {
		        i__1 = leny;
		
          for (i = 1; i <= leny; ++i) 
		        Y(i) = 0.;
		    } else {
		
          i__1 = leny;
		
          for (i = 1; i <= leny; ++i) 
		        Y(i) = *beta * Y(i);
		      }
		      
	    } else {
	         iy = ky;
	          if (*beta == 0.) {
		         i__1 = leny;
		          for (i = 1; i <= leny; ++i) {
		            Y(iy) = 0.;
		            iy += *incy;
		          }
	          } else {
		             i__1 = leny;
		               for (i = 1; i <= leny; ++i) {
		                 Y(iy) = *beta * Y(iy);
		                 iy += *incy;
                   }
	            }
	      }
    }
    
    if (*alpha == 0.) 
	    return 0;
    
    if (trans== "N") {

/*  Form  y := alpha*A*x + y. */

	  jx = kx;
	  
    if (*incy == 1) 
    {
	    i__1 = *n;
	  
      for (j = 1; j <= *n; ++j) {
		    if (X(jx) != 0.) {
		     temp = *alpha * X(jx);
		     i__2 = *m;
		    
         for (i = 1; i <= *m; ++i) 
		  	   Y(i) += temp * A(i,j); 
		   }
		
       jx += *incx;
      
      }
	  } else {
	    i__1 = *n;
	    
      for (j = 1; j <= *n; ++j) 
      {
		   if (X(jx) != 0.) 
       {
		    temp = *alpha * X(jx);
		    iy = ky;
		    i__2 = *m;
		   
        for (i = 1; i <= *m; ++i) {
		    	Y(iy) += temp * A(i,j);
			    iy += *incy;
		    }
		   }
		
       jx += *incx;
	  
      }
	   }
    } else {

/* Form  y := alpha*A'*x + y. */

	      jy = ky;
	      
        if (*incx == 1) {
	        i__1 = *n;
	       
         for (j = 1; j <= *n; ++j) {
		       temp = 0.;
		       i__2 = *m;
		        
            for (i = 1; i <= *m; ++i) 
		          temp += A(i,j) * X(i);

		        
		        Y(jy) += *alpha * temp;
		        jy += *incy;

	       }
	  } else {
	       i__1 = *n;
	    
         for (j = 1; j <= *n; ++j) {
		      temp = 0.;
		      ix = kx;
		      i__2 = *m;
		
           for (i = 1; i <= *m; ++i) {
		        temp += A(i,j) * X(ix);
		        ix += *incx;
           }
         
		      Y(jy) += *alpha * temp;
		      jy += *incy;
	       }
	       
	    }
    }

    return 0;

} /*dgemv_*/



int mydtrsv_(char *uplo, char *trans, char *diag, int *n, double *a, int *lda, double *x, int *incx)
{
  #define X(I) x[(I)-1]
  #define Ax(I,J) a[((I)-1) + ((J)-1)* ( *lda)]

   static double temp;
   static int i, j;    
   static int ix, jx;

    if (trans== "N") /*Form  x := inv( A )*x.*/ /*UPPER*/
    {
     if (uplo== "L") 
     {
	        for (j = 1; j <= *n; ++j) 
          {
		        if (X(j) != 0.) 
            {		      
             temp = X(j);
			      
              for (i = j + 1; i <= *n; ++i) 
                X(i) -= temp * Ax(i,j);
		         
            }
		      
          }
	     		         
	   }
  
    }
        
    return 0;

}   /*dtrsv_*/


void GenerateBcolumn(double *a, int fa, int ca, double *b)
{

 int i,j;
 float suma = 0;
 int cont = 0;
 int ld = fa;
 
  for(i=0; i<fa; ++i)
  {
   for(j=0; j<ca; ++j)
   {
     suma += a[i + j*ld];
     
     if(j == (ca - 1) )
     {
      b[cont++] = suma;
      suma = 0; 
     }   
   }
  }

}/*GenerateBcolumn*/    
  

void PrintVector(double *a,  int n)
{
  int i;

  for(i=0;i<n;i++)
     printf("%1.3lf\t", a[i] );
  
  printf("\n\n");

}/*PrintVector*/


void PrintMatrix(double *a, int fa, int ca, int lda)
{
  int i,j;
  int ld = lda;
  
  for(i=0;i<fa;i++)
  {
    for(j=0;j<ca;j++)
     printf("%1.3lf\t",a[i + j*ld]);
    
    printf("\n");
  
  }
  printf("\n");

}/*PrintMatrix*/


void CreateMatrixLower(double *_matrix, int _rows)
{
     
      for(int i = 0; i < _rows; ++i)
	    { 
       for(int j = 0; j < _rows; ++j)
	     {                   
         
         if(i == j)
           _matrix[i + j*_rows] =  1;
         
          else
          { 
            if(i > j)
              _matrix[i + j*_rows] = i + j;       
              
              else
                _matrix[i + j*_rows] = 0;      
            
          }
        }
       }

}/*CreateMatrixLower*/



void dtrsvforblocks(double *Ao, int n, double *X, int tb)
{
  int i, j;
  int lda = n;
  int incx=1;
  double alpha = -1.;
  double beta =  1.;
  
        for(j = 0  ; j < n ; j+=tb) 
        {      
           PrintMatrix(Ao+j+lda*j,tb,tb,n);
           mydtrsv_( "L" , "N" , "U" ,&tb , Ao+j+lda*j , &lda , X+j , &incx );
           PrintVector(X,n);
          
           for (i = j + tb; i < n; i+=tb) 
           {
              PrintMatrix(Ao+i+lda*j,tb,tb,n);
              mydgemv_("N", &tb, &tb, &alpha, Ao+i+lda*j, &lda, X+j, &incx, &beta, X+i, &incx);   
        
           }
           PrintVector(X,n);
         }
  
}/*dtrsvforblocks*/

int main(int	argc, char	*argv[])
{
  if((argc == 1)||(argc == 2) ) return 1;

  int n = atoi(argv[1]);
  int tb = atoi(argv[2]);
  
  double *Ao =(double *) malloc(sizeof(double)*(n*n));
  double *X  =(double *) malloc(sizeof(double)*(n));
  
  CreateMatrixLower(Ao, n); 
  PrintMatrix(Ao, n, n, n);
  
  GenerateBcolumn(Ao, n, n, X);
  PrintVector(X, n);
 
   /****************************************/
   /**/  dtrsvforblocks(Ao, n, X, tb);   /**/ 
   /***************************************/
   
  PrintVector(X, n);

  free(Ao);
  free(X);

  return 0;

}/*main*/