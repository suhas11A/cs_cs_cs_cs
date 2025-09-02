x = -3:0.02:3;
y = 6.5*sin(2.1*x + pi/3);


function s = all(f,y,x)
    figure;
    plot(x,y,'r','LineWidth', 1.5); hold on

    % corrupted sine wave
    sub_size = round(f*numel(y));
    n = numel(y);
    idx = randperm(numel(y), sub_size);
    rand_vals = 100 + 20 .* rand(1, sub_size);
    z=y;
    z(idx) = z(idx) + rand_vals;
    plot(x,z,'b','LineWidth',1);hold on
    
    % moving median filtering, moving mean filtering and moving quartile filtering
    for i = 1:n
        y_median(i) = median(z(max(i-8,1):min(n,i+8)));
        y_mean(i) = mean(z(max(i-8,1):min(n,i+8)));
        y_25_quartile(i) = prctile(z(max(i-8,1):min(n,i+8)),25);
    end
    
    % plot filtered signals
    plot(x, y_median,'g', 'LineWidth', 1.5); hold on
    plot(x, y_mean, 'y', 'LineWidth', 1.5); hold on
    plot(x, y_25_quartile,'w--', 'LineWidth', 1.5); 
    legend('clean','corrupted','mov median','mov mean','mov quartile');
    hold off
    
    % calculate relative mean square errors
    rmse_mean = sum((y-y_mean).^2)/sum((y).^2);
    rmse_median = sum((y-y_median).^2)/sum((y).^2);
    rmse_25q = sum((y-y_25_quartile).^2)/sum((y).^2);
    
    fprintf('f = %.0f%%\n', f*100);
    fprintf('RMSE Quartile: %.6f\n', rmse_25q);
    fprintf('RMSE Median:   %.6f\n', rmse_median);
    fprintf('RMSE Mean:     %.6f\n\n', rmse_mean);
    s=1;
end

s=all(0.3,y,x);
s=all(0.6,y,x);