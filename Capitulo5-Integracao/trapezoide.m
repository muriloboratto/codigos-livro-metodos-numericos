%****************************************************************************80
%  Code: 
%   trapezoide.m 
%
%  Purpose:
%   Implements the simpson method for integration area
%
%  Modified:
%   Jul 25 2021 16:34 
%
%  Author:
%    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
%   
%  How to Execute:
%    s = trapeze(f, a, b, n)
%   
%  Comments:
%
%  Input parameters:
%      f - the function must be entered as a string
%    a,b - range [a, b]
%      n - number of subintervals  
%   
%  Output parameters:
%      s - the approximate value of the integral obtained by the rule
%
%*****************************************************************************

function s = trapezoide(f, a, b, n)

 h=(b-a)/n;   
 x=a;          
 y=eval(f);    
 s=h/2*y;  

 for k=1:(n-1); 
  x=a+h*k; 
  y=eval(f);   
  s=s+h*y; 
 end

 x=b;           
 y=eval(f);     
 s=s+h/2*y; 
