%****************************************************************************80
%  Code: 
%   simpson.m 
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
%    s = simpson(f, a, b, n)
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

function s = simpson(f,a,b,n)

if mod(n,2)~=0
  disp ('The number of intervals must be even');
    else
      format short; 
      h=(b-a)/n;                   
      x=zeros(1,n+1);

      x(1)=a;
      x(n+1)=b;

      for k=2:n
       x(k)=x(k-1)+ h;
      end

      y=eval(f);
      disp('x= '), disp(x);
      disp('f(x)= '), disp(y);

      s = y(1) + 4 * y(2); 

      if(n==2)
       s=s+y(3);
       format long;
       s=(h/3) * s; 
         else
           for k=3:(n-1);   
             s=s+2*y(k); 
           end
           s=s+4*y(n)+y(n+1); 
           format long;
           s =(h/3) * s; 
       end
       
end
