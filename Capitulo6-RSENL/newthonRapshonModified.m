%****************************************************************************80
%  Code: 
%   newthonRapshonModified.m 
%
%  Purpose:
%   Implements the newton method for nolinear system.
%
%  Modified:
%   Jul 25 2021 16:34 
%
%  Author:
%    Murilo Do Carmo Boratto [muriloboratto@uneb.br]  
%   
%  How to Execute:
%    newthon_rapshon_modified
%   
%  Comments:
%
%*****************************************************************************

function newthon_rapshon_modified()

%%Example 1%%
%%F1=inline('x^2 + y^2 - 2');
%%F2=inline('x^2 - y^2 - 1');
%%F1x=inline('2*x');  F1y=inline('2*y');
%%F2x=inline('2*x');  F2y=inline('-2*y');
%%Jacob=inline('(2*x)*(-2*y)-(2*x)*(2*y)');
%%xi=1.2; 
%%yi=0.7;
%%Err=0.1;

%%Example 2%%
F1=inline('x^2 + y^2 - 2');
F2=inline('exp(x-1) + y^3 - 2');
F1x=inline('2*x');       F1y=inline('2*y');
F2x=inline('exp(x-1)');  F2y=inline('3*y^2');
Jacob=inline('(2*x)*(3*y^2)-(2*y)*(exp(x-1))');
xi=1.5; 
yi=2;
Err=0.1;

  for i = 1 : 5
    
    Jac = Jacob(xi,yi);
    
    Delx = (-F1(xi,yi)*F2y(yi) + F2(xi,yi)*F1y(yi))  / Jac;
    Dely = (-F2(xi,yi)*F1x(xi) + F1(xi,yi)*F2x(xi))  / Jac;
    
    xipl = xi+Delx;
    yipl = yi+Dely;
    
    Errx = abs((xipl-xi)/xipl);
    Erry = abs((yipl-yi)/yipl);
    
    fprintf('i=(%d) x=%7.4f y=%7.4f [Errox=%7.4f] [Erroy=%7.4f]\n',i,xipl,yipl,Errx,Erry)
   
    if((Errx < Err) && (Erry < Err))
       break   
    else
       xi=xipl;
       yi=yipl;
    end
   
  end 
  
end 
