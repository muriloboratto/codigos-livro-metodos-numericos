/****************************************************************************80
*  Code: 
*   fixPoint.c 
*
*  Purpose:
*   Implements de C code with the Fix Point method for finding roots.
*   The method consist in the p = g(p) given an initial approximation p0.
*
*  Modified:
*   Jan 20 2018 10:42 
*
*  Author:
*    Murilo Do Carmo Boratto [muriloboratto@uneb.br]
*
*  Compile:
*    gcc pontofixo.c -o objeto -lm 
*   
*  Execute:
*    ./objeto  
*
*  Comments:
*   Example: f(x) = 4x^2+4x-10    --> g(x) = sqrt(10/(4+x))
*
*******************************************************************************/

#include <stdio.h>
#include <math.h> 
#include <stdlib.h> 

#define true 1
#define false 0

void INPUT(int *, double *, double *, int *);
void OUTPUT(FILE **, int *);
double absval(double);
double G(double ); 

int main(int argc, char **argv){

   double TOL,P0,P;
   int I,NO,FLAG,OK;
   char AA;
   FILE *OUP[1];

   INPUT(&OK, &P0, &TOL, &NO);

   if (OK){
      
      OUTPUT(OUP, &FLAG); 
      I = 1; 
      OK = true; 
      
      while((I<=NO) && OK){
         P = G(P0);
      
         if (FLAG == 2) 
            fprintf(*OUP, "%3d   %1.6f\n", I, P);
        
         if (absval(P-P0) < TOL){ 
            fprintf(*OUP, "  Approximate solution x = %12.8f\n", P);
            fprintf(*OUP, "  Number of Iterations = %3d\n", I);
            fprintf(*OUP, "  Tolerance = %14.8f\n",TOL);
            OK = false;
         }
           else{
            I++;
            P0 = P; 
           }/*else*/
           
       }/*while*/
   
      if (OK){
         fprintf(*OUP, " Approximate solution x = %12.8f\n", P);
         fprintf(*OUP, " Number of Iterations = %3d\n", NO);
         fprintf(*OUP, " Tolerance =   %14.8e\n",TOL);
      }/*if*/
      
      fclose(*OUP);
   
   }/*if*/
     
   return 0;
   
}/*main*/


double G(double X){
  double g;
  
   return g = sqrt(10.0 / (4.0 + X)); 
   
}/*G*/


void INPUT(int *OK, double *P0, double *TOL, int *NO){

   char AA='Y';

   printf(":::: Fix Point Method ::::\n");
   
   if ((AA == 'Y') || (AA == 'y')){
      *OK = false;
      printf("Initial point (x0):\n");
      scanf("%lf", P0); 
      
      while(!(*OK)) 
      {
         printf("Tolerance (t):\n");
         scanf("%lf", TOL);
         
         if (*TOL <= 0.0) 
            printf("Error: The tolerance needs to be positive\n");
              else 
                *OK = true;
      }/*while*/
      
      *OK = false;
      
      while (!(*OK)) {
         printf("Number of maximum iterations:\n");
         scanf("%d", NO);
         
         if (*NO <= 0) 
            printf("Error: The maximum number of iterations needs to be a integer number\n");
           else 
             *OK = true;
      }/*while*/
   
   }/*if*/
   
   else{
      printf("Error: The G function not converge to the desired value!\n");
      *OK = false;
   }/*else*/
   
}/*INPUT*/

void OUTPUT(FILE **OUP, int *FLAG){

   char NAME[30];

   printf("Print solution:\n");
   printf("1. Screen\n");
   printf("2. File\n");
   printf("Dial 1 or 2\n");
   scanf("%d", FLAG);
 
   if (*FLAG == 2){
      printf("Generate the solution: path://name.ext\n");
      printf("Example:  c://output.dat\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
 
   else 
    *OUP = stdout;
   
   printf("Select the output:\n");
   printf("1. Only the approximate solution.\n");
   printf("2. Todas as solucoes aproximadas.\n");
   printf("Dial 1 or 2\n");
   scanf("%d", FLAG);
   fprintf(*OUP, ":::: Fix Point Method ::::\n"); 
   
   if (*FLAG == 2) 
       fprintf(*OUP, "  I        P\n");

}/*INPUT*/   

double absval(double val){

   if (val >= 0) 
      return val;
         else 
           return -val;
} /*absval*/

