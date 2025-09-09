clear; close all; clc;

I1=double(imread('T1.jpg'));
I2=double(imread('T2.jpg'));

% shift I2
function shifted=shift(I2,tx)
    [rows,cols]=size(I2);
    shifted=zeros(rows,cols);
    if tx>0
        shifted(:,(tx+1):end)=I2(:,1:(end-tx));
    elseif tx<0
        shifted(:,1:end+tx) = I2(:,-tx+1:cols);
    else
        shifted=I2;
    end
end

% zero to unoccupied cells
function zeroed=make_zeroes(I1,shifted_I2)
    zeroed=(I1~=0)&(shifted_I2~=0);
end

% joint histogram
function joint=joint_hist(i1,i2)
  ind1=floor(i1(:)./10)+1;
  ind2=floor(i2(:)./10)+1;
  for i=1:length(ind1)
      if(ind1(i)>26)
          ind1(i)=26;
      elseif(ind1(i)<1)
          ind1(i)=1;
      end
      if(ind2(i)>26)
          ind2(i)=26;
      elseif(ind2(i)<1)
          ind2(i)=1;
      end
  end
  hist_vals=zeros(26,26);
  for i=1:length(ind1)
      hist_vals(ind1(i),ind2(i))=hist_vals(ind1(i),ind2(i))+1;
  end
  total=0;
    for i=1:26
        for j=1:26
            total=total+hist_vals(i,j);
        end
    end
    joint=hist_vals./total;
end

function [rhos,qmis,mis]=dependence(I1,I2)
    tx_vals=-10:10;
    rhos=zeros(length(tx_vals),1);
    qmis=zeros(length(tx_vals),1);
    mis=zeros(length(tx_vals),1);
    for k=1:length(tx_vals)
        tx=tx_vals(k);
        shifted_i2=shift(I2,tx);
        zeroed=make_zeroes(I1,shifted_i2);
        v1=I1(zeroed);
        v2=shifted_i2(zeroed);

        %correlation coefficient
        v1m=mean(v1);
        v2m=mean(v2);
        cov12=mean((v1-v1m).*(v2-v2m));
        s1=std(v1,1);
        s2=std(v2,1);
        if s1*s2==0
            rhos(k)=0;
        else
            rhos(k)=cov12/(s1*s2);
        end
        % joint histogram
        joint_p=joint_hist(v1,v2);
        marginal_p1=sum(joint_p,2);
        marginal_p2=sum(joint_p,1)';
        
        % qmi
        d=marginal_p1*marginal_p2';
        f=joint_p-(d);
        qmis(k)=sum(f(:).^2);
        % mi
        idx=(joint_p>0)&(d>0);
        mis(k)=sum(joint_p(idx).*log(joint_p(idx)./d(idx)));

    end

end

[rhos1,qmis1,mis1]=dependence(I1,I2);

I2_neg=255-I1;
[rhos2,qmis2,mis2]=dependence(I1,I2_neg);

I2_quad=255*(I1.^2)/max(I1(:).^2)+1;
[rhos3,qmis3,mis3]=dependence(I1,I2_quad);

tx_vals=-10:10;


% original I2 
figure;
plot(tx_vals,rhos1,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('\rho');
title('Correlation vs shift (Original I2)');

figure;
plot(tx_vals,qmis1,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('QMI');
title('QMI vs shift (Original I2)');

figure;
plot(tx_vals,mis1,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('MI');
title('MI vs shift (Original I2)');

% negative I2
figure;
plot(tx_vals,rhos2,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('\rho');
title('Correlation vs shift (Negative I2)');

figure;
plot(tx_vals,qmis2,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('QMI');
title('QMI vs shift (Negative I2)');

figure;
plot(tx_vals,mis2,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('MI');
title('MI vs shift (Negative I2)');

% quadratic I2 
figure;
plot(tx_vals,rhos3,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('\rho');
title('Correlation vs shift (Quadratic I2)');

figure;
plot(tx_vals,qmis3,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('QMI');
title('QMI vs shift (Quadratic I2)');

figure;
plot(tx_vals,mis3,'r-','LineWidth',1.5);
xlabel('tx'); ylabel('MI');
title('MI vs shift (Quadratic I2)');
