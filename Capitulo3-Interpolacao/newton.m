%****************************************************************************80
%  Code: 
%   newton.m 
%
%  Purpose:
%   Implements the Newton Interpolation P(x)
%   
%  Modified:
%   Jul 25 2021 16:34 
%
%  Author:
%    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
%   
%  How to Execute:
%   [C] = newton(X,Y)
%   [C,D] = newton(X,Y)
%  
%  Comments:
%
%  Input parameters:
%    X abscissa vector
%    Y ordinate vector
%   
%  Output parameters:
%    C vector with the coefficients of the Newton interpolator polynomial
%    D the table of divided differences
%
%*****************************************************************************

function [C,D] = newton(X,Y)

n = length(X);        
D = zeros(n,n);       
D(:,1) = Y;           

for j=2:n           
  for k=j:n          
    D(k,j) = (D(k,j-1)-D(k-1,j-1))/(X(k)-X(k-j+1));
  end
end

C = D(n,n);

for i=(n-1):-1:1
  C = conv(C,poly(X(i)));
  m = length(C);
  C(m) = C(m) + D(i,i);
end
 
