D=dlmread('XYZ.txt'); 
N=size(D,1);
x=D(:,1);  
y=D(:,2);  
z=D(:,3);

%lhs
sumxx=sum(x.^2);
sumxy=sum(x.*y);
sumx=sum(x); 
sumyy=sum(y.^2); 
sumy=sum(y);

%rhs
sumxz=sum(x.*z);    
sumyz=sum(y.*z);
sumz=sum(z);

A=[sumxx,sumxy,sumx;
   sumxy,sumyy,sumy;
   sumx,sumy,N];
B=[sumxz;sumyz;sumz];

% finding a,b,c
coef=A\B;
a=coef(1);  
b=coef(2);  
c=coef(3);

%sigma^2
X=[x,y,ones(N,1)];
sigma2=norm(z- X*coef)^2/N;  

fprintf('Predicted equation of plane:  z = %.10f * x + %.10f * y + %.10f\n',a,b,c);
fprintf('Predicted noise variance:     sigma^2 = %.10g\n', sigma2);

