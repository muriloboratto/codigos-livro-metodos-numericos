%****************************************************************************80
%  Code: 
%   gauss.m 
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
%    s = gauss(f, a, b, nS)
%   
%  Comments:
%
%  Input parameters:
%      f - the function must be entered as a string
%    a,b - range [a, b]
%     nS - number of subintervals [1;6]
%   
%  Output parameters:
%      s - the approximate value of the integral obtained by the rule
%
%*****************************************************************************

function s = gauss(f, a, b, nS)

if ~(0 < nS & nS < 7)
    error('Error: The number of sub-ranges must be between 1 and 6.')
end    

n = nS + 1; 

        fprintf('\n')
        disp('              Gauss Method for Interpolation ')
        disp('_________________________________________________________')
        disp(' i       ti           Pi          F(ti)        Pi*F(ti)  ')
        disp('_________________________________________________________')

if (n==2) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 1 subinterval
   z(1)=-sqrt(1/3); 
   z(2)=-z(1);      
   w(1)=1; w(2)=1;
  elseif (n==3) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 2 subintervals 
   z(1)=-sqrt(3/5); 
   z(2)=0;
   z(3)=-z(1);
   w(1)=5/9; w(2)= 8/9; w(3)=w(1);
  elseif (n==4) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 3 subintervals 
   z(1)=-sqrt(1/7*(3-4*sqrt(0.3)));
   z(2)=-sqrt(1/7*(3+4*sqrt(0.3)));
   z(4)=-z(1);
   z(3)=-z(2);
   w(1)=1/2+1/12*sqrt(10/3);
   w(2)=1/2-1/12*sqrt(10/3);
   w(4)=w(1); w(3)=w(2);
  elseif (n==5) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 4 subintervals 
   z(1)=-sqrt(1/9*(5-2*sqrt(10/7)));
   z(2)=-sqrt(1/9*(5+2*sqrt(10/7)));
   z(3)=0;
   z(4)=-z(2);
   z(5)=-z(1);
   w(1)=0.3*((-0.7+5*sqrt(0.7))/(-2+5*sqrt(0.7)));
   w(2)=0.3*((0.7+5*sqrt(0.7))/(2+5*sqrt(0.7)));
   w(3)=128/225;
   w(5)=w(1); 
   w(4)=w(2);
  elseif (n==6) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 5 subintervals 
   z(1)=-0.932469514;
   z(2)=-0.661209386;
   z(3)=-0.238619186;
   z(4)= 0.238619186;
   z(5)= 0.661209386;
   z(6)= 0.932469514;
   w(1)= 0.1713245;
   w(2)= 0.3607616;
   w(3)= 0.4679139;
   w(4)= 0.4679139; 
   w(5)= 0.3607616; 
   w(6)= 0.1713245; 
elseif (n==7) %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 6 subintervals 
   z(1)=-0.9491079123;
   z(2)=-0.7415311855;
   z(3)=-0.4058451513;
   z(4)= 0;
   z(5)= 0.4058451513;
   z(6)= 0.7415311855;
   z(7)= 0.9491079123; 
   w(1)= 0.1294849661;
   w(2)= 0.2797053914;
   w(3)= 0.3818300505;
   w(4)= 0.4179591836; 
   w(5)= 0.3818300505; 
   w(6)= 0.2797053914; 
   w(7)= 0.1294849661; 
end;

 f = fcnchk(f);
 S = 0;
 
 for i=1:n
   x = ((b-a)*z(i)+a+b)/2;
   g = feval(f,x);
   S = S+w(i)*g;
 
       fprintf('%2.0f %12.4f %12.4f% 12.4f %12.4f\n',i-1,z(i),w(i),g,g*w(i));
  
  end;

 I = S *(b-a)/2;

 fprintf('\n           Integration f(x) = %16.8f\n', I); 

end

