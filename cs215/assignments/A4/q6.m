clear;clc;close all;
[I_train,labels,I_test,labels_test] = readMNIST();

for i=1:10
    index=find(labels==(i-1));
    m=numel(index);

    % matrix of all the training data for the number (i-1), so its 784*m 
    all_matrices_with_i=zeros(784,m,'double'); 
    for j=1:m
        row=I_train{index(j)};
        row=row.';
        all_matrices_with_i(:,j)=double(row(:));  
    end

    % eigenvalue plot
    mean_of_cols=mean(all_matrices_with_i,2);
    diff=all_matrices_with_i-mean_of_cols;
    covariance_matrix =(diff * diff.')/(m-1); 
    [eigenvectors, eigenvalues] = eig(covariance_matrix);
    [sorted_eigen,des]=sort(diag(eigenvalues),'descend');

    figure();
    plot(sorted_eigen,'LineWidth',2);
    ylim([0, max(sorted_eigen)*1.05]);
    
    % eigenvector plots
    figure();
    for k=1:5
        curr=eigenvectors(:,des(k));
        reshaped=reshape(curr,28,28);
        mini=min(reshaped(:));
        maxi=max(reshaped(:));
        reshaped=(reshaped-mini)/(maxi-mini);
        subplot(1,5,k);
        imshow(reshaped);
    end
end
