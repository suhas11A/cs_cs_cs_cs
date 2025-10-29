n = 10000;


function X = sample_gauss_a(n)
    mu = [1; 1];
    A  = [3 0; 0 2];
    Z  = randn(2, n);
    X  = (A * Z) + mu;
    X  = X.';
end

function X = sample_gauss_b(n)
    mu = [1; 2];
    A  = [3, 0; 1/3, sqrt(35)/3];
    Z  = randn(2, n);
    X  = (A * Z) + mu;
    X  = X.';
end

function [v_min,v_max,th_min,th_max,var_min,var_max,theta,vars] = sweep_var_dirs(X)
    Xc = X - mean(X,1);
    theta = linspace(0, 2*pi, 1000);
    vars  = zeros(size(theta));
    for k = 1:numel(theta)
        v = [cos(theta(k)); sin(theta(k))];
        y = Xc * v;
        vars(k) = mean(y.^2);
    end
    [var_max, iMax] = max(vars);
    [var_min, iMin] = min(vars);
    th_max = theta(iMax);  v_max = [cos(th_max); sin(th_max)];
    th_min = theta(iMin);  v_min = [cos(th_min); sin(th_min)];
end

X1 = sample_gauss_a(n);
X2 = sample_gauss_b(n);

[vmin1,vmax1,thmin1,thmax1,varmin1,varmax1,theta1,vars1] = sweep_var_dirs(X1);
figure(1); clf;
scatter(X1(:,1), X1(:,2), 30, 'filled');
axis equal; grid on;
xlabel('x_1'); ylabel('x_2');
title('Samples from N([1;1], [9 0; 0 4])');

mu1 = mean(X1,1);
L = 10;
hold on; plot(mu1(1)+[-L L]*vmax1(1), mu1(2)+[-L L]*vmax1(2), 'b-', 'LineWidth', 2);
plot(mu1(1)+[-L L]*vmin1(1), mu1(2)+[-L L]*vmin1(2), 'r-', 'LineWidth', 2);
fprintf('\nCase (a): N([1;1],[9 0; 0 4])\n');
fprintf('  v_max (empirical) = [%.6f  %.6f]^T,  Var ≈ %.6f\n', ...
        vmax1(1), vmax1(2), varmax1);
fprintf('  v_min (empirical) = [%.6f  %.6f]^T,  Var ≈ %.6f\n', ...
        vmin1(1), vmin1(2), varmin1);

[vmin2,vmax2,thmin2,thmax2,varmin2,varmax2,theta2,vars2] = sweep_var_dirs(X2);
figure(2); clf;
scatter(X2(:,1), X2(:,2), 30, 'filled');
axis equal; grid on;
xlabel('x_1'); ylabel('x_2');
title('Samples from N([1;2], [9 1; 1 4])');

mu2 = mean(X2,1);
L = 10;
hold on; plot(mu2(1)+[-L L]*vmax2(1), mu2(2)+[-L L]*vmax2(2), 'b-', 'LineWidth', 2);
plot(mu2(1)+[-L L]*vmin2(1), mu2(2)+[-L L]*vmin2(2), 'r-', 'LineWidth', 2);
fprintf('\nCase (b): N([1;2],[9 1; 1 4])\n');
fprintf('  v_max (empirical) = [%.6f  %.6f]^T,  Var ≈ %.6f\n', ...
        vmax2(1), vmax2(2), varmax2);
fprintf('  v_min (empirical) = [%.6f  %.6f]^T,  Var ≈ %.6f\n', ...
        vmin2(1), vmin2(2), varmin2);