%% Mean

function newMean = UpdateMean (OldMean, NewDataValue, n)
    newMean = OldMean + (NewDataValue - OldMean) / (n + 1);
end

%% Median

function newMedian = UpdateMedian (oldMedian, NewDataValue, A, n)
    % I did not make use of oldMedian, but this does run in constant time and does not loop through the entire array.
    x = NewDataValue;
    if (n == 0)
        newMedian = x;
    elseif (n == 1)
        newMedian = (A(1) + x)/2;
    elseif (mod(n,2) == 0)
        small = A(n/2);
        big = A(n/2 + 1);
        newMedian = median([small,big,x]);
    else
        ind = (n + 1)/2;
        mid = A(ind);
        if x < mid
            newMedian = (max([A(ind-1), x]) + mid)/2;
        else
            newMedian = (mid + min([A(ind+1), x]))/2;
        end
    end
end

%% Standard Deviation

function newStd = UpdateStd(OldMean, OldStd, NewMean, NewDataValue, n)
    % sq_sum_old = (n-1) * (OldStd ^ 2) + n*(OldMean^2);
    % var_new = (sq_sum_old + NewDataValue^2 - (n+1)*(NewMean^2))/n;
    var_new = ((n-1) * (OldStd ^ 2) + n*(OldMean^2) + NewDataValue^2 - (n+1)*(NewMean^2))/n;
    newStd = sqrt(var_new);
end

%% Testing

valid = true;
for n = 1:2000
    A = sort(randn(1,n));
    oldMean = mean(A);
    oldStd  = std(A,0);
    oldMedian = median(A);
    x = randn();
    m1 = UpdateMedian(oldMedian, x, A, n);
    m2 = median([A, x]);
    mean1 = UpdateMean(oldMean, x, n);
    mean2 = mean([A, x]);
    std1 = UpdateStd(oldMean, oldStd, mean1, x, n);
    std2 = std([A, x], 0);
    if ( (abs(m1 - m2)>1e-12) || (abs(mean1 - mean2)>1e-12) || (abs(std1 - std2)>1e-12) )
        valid = false;
        break;
    end
end

if valid
    disp('All good for mean, median, and std!');
else 
    disp('Bad code, try again!')
end