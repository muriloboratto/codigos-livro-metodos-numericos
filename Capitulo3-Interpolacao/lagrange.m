%****************************************************************************80
%  Code: 
%   lagrange.m 
%
%  Purpose:
%   Implements the Lagrange Interpolation Px
%   
%  Modified:
%   Jul 25 2021 16:34 
%
%  Author:
%    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
%   
%  How to Execute:
%   [C]   = lagrange(X,Y)
%   [C,L] = lagrange(X,Y)
%  
%  Comments:
%
%    Input parameters:
%      X abscissa vector
%      Y ordinate vector
%
%    Output parameters:
%      C vector with the coefficients of the Lagrange interpolator polynomial
%      L matrix with the coefficients of the Lagrange polynomials
%*****************************************************************************

function [C,L] = lagrange(X,Y)
echo off;

n = length(X);             
L = zeros(n,n);            

for k=1:n,               
  V = 1;
  for i=1:n,
    if i ~= k
      V = conv(V,poly(X(i)));
      V = V/(X(k)-X(i)); 
    end
  end

  L(k,:) = V;
   
end

C = Y * L;                   
                                                     
