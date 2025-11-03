```n  = 1000;
X  = 4 * randn(1,n);
idx = randperm(n);
T   = X(idx(1:(3*n/4)));
V   = X(idx((3*n/4 + 1):end));

function anss = kde_gauss(V, T, sigma)
    anss = 0;
    for j = 1:length(V)
        x = V(j);
        p = 0;
        for i = 1:length(T)
            t = T(i);
            k = exp(-0.5*((x-t)/sigma)^2);
            p = p+k;
        end
        p = p / (length(T)*sigma*(2*pi)^0.5);
        p = log(p);
        anss = anss + p;
    end
end


sigmas = [0.001,0.1,0.2,0.9,1,2,3,5,10,20,100];
LL = zeros(size(sigmas));

for k = 1:length(sigmas)
    s = sigmas(k);
    pV = kde_gauss(V, T, s);
    LL(k) = pV;
end

[LLbest, ibest] = max(LL);
sigma_best_LL = sigmas(ibest);
fprintf('Best LL = %.6f at sigma = %.6g\n', LLbest, sigma_best_LL);

figure; plot(log(sigmas), LL, 'o-','LineWidth',1.5); grid on;
xlabel('log \sigma'); ylabel('LL(\sigma)'); title('Validation log-likelihood vs log(\sigma)');

% For the best sigma
xgrid = -8:0.1:8;
p_hat = zeros(size(xgrid));
for j = 1:length(xgrid)
    x = xgrid(j);
    k = exp(-0.5*((x - T)/sigma_best_LL).^2);
    p_hat(j) = sum(k) / (length(T)*sigma_best_LL*sqrt(2*pi));
end
p_true = exp(-0.5*((xgrid - 0)./4).^2) ./ (4*sqrt(2*pi));
figure; plot(xgrid, p_hat, 'LineWidth',1.5); hold on;
plot(xgrid, p_true, '--', 'LineWidth',1.5); grid on;
legend('KDE','True N(0,16)','Location','best');
xlabel('x'); ylabel('density'); title(sprintf('KDE vs True (\\sigma^*_{LL}=%.3g)', sigma_best_LL));





D = zeros(size(sigmas));
pV_true = exp(-0.5*(V./4).^2) ./ (4*sqrt(2*pi));

for k = 1:numel(sigmas)
    s = sigmas(k);
    pV_hat = zeros(size(V));
    for j = 1:length(V)
        x = V(j);
        k_vals = exp(-0.5*((x - T)/s).^2);
        pV_hat(j) = sum(k_vals) / (length(T)*s*sqrt(2*pi));
    end
    D(k) = sum((pV_true - pV_hat).^2);
end

[Dbest, jbest] = min(D);
sigma_best_D = sigmas(jbest);
fprintf('Best D = %.6g at sigma = %.6g\n', Dbest, sigma_best_D);
fprintf('D at sigma_best_LL (%.6g) is %.6g\n', sigma_best_LL, D(sigmas==sigma_best_LL));
fprintf('Minimal D at sigma_D* = %.6g is D* = %.6g\n', sigma_best_D, Dbest);

figure; plot(log(sigmas), D, 's-','LineWidth',1.5); grid on;
xlabel('log \sigma'); ylabel('D(\sigma)'); title('Squared error vs log(\sigma)');

% Overlay curves for sigma_best_D
xgrid = (-8:0.1:8).';
p_hat_D = zeros(size(xgrid));
for j = 1:length(xgrid)
    x = xgrid(j);
    k_vals = exp(-0.5*((x - T)/sigma_best_D).^2);
    p_hat_D(j) = sum(k_vals) / (length(T)*sigma_best_D*sqrt(2*pi));
end
p_true = exp(-0.5*((xgrid - 0)./4).^2) ./ (4*sqrt(2*pi));

figure; plot(xgrid, p_hat_D, 'LineWidth',1.5); hold on;
plot(xgrid, p_true, '--', 'LineWidth',1.5); grid on;
legend('KDE','True N(0,16)','Location','best');
xlabel('x'); ylabel('density'); 
title(sprintf('KDE vs True (\\sigma^*_{D}=%.3g)', sigma_best_D));```