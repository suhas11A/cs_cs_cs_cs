%% Part (c): Expected tests vs prevalence p (n = 1000)
clear; clc;

n = 1000;
p_list = [1e-4, 5e-4, 0.001, 0.005, 0.01, 0.02, 0.05, 0.08, 0.1, 0.2];

Ta_opt = zeros(size(p_list));
s_opt  = zeros(size(p_list));
Tb_opt = zeros(size(p_list));
T1_opt = zeros(size(p_list));
pi_opt = zeros(size(p_list));

for idx = 1:numel(p_list)
    p = p_list(idx);

    %% ---------- Method (a): disjoint pools of size s ----------
    bestT = inf; bestS = NaN;
    for s = 1:n
        ps_pow = exp(s * log1p(-p));
        T = n/s + n*(1 - ps_pow);
        if T < bestT
            bestT = T; bestS = s;
        end
    end
    Ta_opt(idx) = bestT; s_opt(idx) = bestS;

    %% ---------- Method (b): overlapping random pools ----------
    % E(T1,pi) = T1 + n*p + n*(1-p) * [ 1 - pi * (1 - p*pi)^(n-1) ]^T1
    % pi* = min(1, 1/(n*p))
    pi_star = min(1, 1/(n*p));
    pi_opt(idx) = pi_star;

    % Compute B = 1 - pi_star * (1 - p*pi_star)^(n-1) with a stable power
    pow_term = exp((n-1) * log1p(-p*pi_star));
    B = 1 - pi_star * pow_term;

    if n*(1-p)*(-log(B)) > 1
        T1_real = log( -1 / (n*(1-p)*log(B)) ) / log(B);
        cand = unique(max(1,floor(T1_real-6)):ceil(T1_real+6));
    else
        cand = 1;
    end

    % Always include T1 = 1 as a candidate
    cand = unique([1, cand]);

    % Evaluate expectation on candidates and choose the best integer
    bestTb = inf; bestT1 = NaN;
    for T1 = cand
        E = T1 + n*p + n*(1-p) * (B^T1);
        if E < bestTb
            bestTb = E; bestT1 = T1;
        end
    end
    Tb_opt(idx) = bestTb; T1_opt(idx) = bestT1;
end

%% ---------- Plot ----------
figure('Units','pixels','Position',[100 100 900 380]); hold on;
semilogx(p_list, Ta_opt, '-o', 'LineWidth', 1.8, 'MarkerSize', 7); 
semilogx(p_list, Tb_opt, '-s', 'LineWidth', 1.8, 'MarkerSize', 7); 
grid on;
xlabel('Prevalence p (log scale)', 'FontSize', 12);
ylabel('Expected number of tests', 'FontSize', 12);
title(sprintf('Expected tests vs prevalence (n = %d)', n), 'FontSize', 12);
legend({'Method (a): optimal s', 'Method (b): optimal \pi, T_1'}, 'Location', 'northwest');

%% ---------- Print table ----------
T = table(p_list.', Ta_opt.', s_opt.', Tb_opt.', T1_opt.', pi_opt.', ...
    'VariableNames', {'p', 'MethodA_MinTests', 's_opt', 'MethodB_MinTests', 'T1_star', 'pi_opt'});
disp(T);
