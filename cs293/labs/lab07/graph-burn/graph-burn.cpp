#include "graph-burn.h"


Graph::Graph(int n) : n(n), adj(n + 1) {}

void Graph::add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// ------------------------------------------------------------
// BFS-based Verifier
// ------------------------------------------------------------
bool verify_burning(const Graph& G, const std::vector<int>& schedule) {
    int lenn = schedule.size();
    if (!lenn) return !G.n;
    std::vector<bool> visited(G.n + 1, false);
    for (int i=0;i<lenn;i++) {
        std::vector<bool> was = visited;
        for (int j=1;j<=G.n;j++) {
            if (!was[j]) continue;
            for (int mi_child : G.adj[j]) visited[mi_child] = true;
        }
        visited[schedule[i]] = true;
    }
    for (int tempo = 1;tempo<=G.n;tempo++) {
        if (!visited[tempo]) return false;
    }
    return true;
}

// ------------------------------------------------------------
// Brute Force Exact Solver (exponential, for small n)
// ------------------------------------------------------------

std::vector<std::vector<int>> generate(int n,int k) {
    if (k==0) return {{}};
    auto tempo = generate(n, k-1);
    std::vector<std::vector<int>> ans;
    for (auto k_1 : tempo) {
        std::vector<bool> visited(n+1, false);
        for (auto i : k_1) visited[i] = true;
        std::set<int> remaining;
        for (int i=1;i<=n;i++) {
            if (!visited[i]) remaining.insert(i);
        }
        for (int i : remaining) {
            auto my_temp = k_1;
            my_temp.push_back(i);
            ans.push_back(my_temp);
        }
    }
    return ans;
}

std::pair<int, std::vector<int>> brute_force_burning(const Graph& G) {
    if (!G.n) return {};
    for (int k=1;k<=G.n;k++) {
        std::vector<std::vector<int>> anso = generate(G.n, k);
        for (auto hehe : anso) {
            if (verify_burning(G, hehe)) return make_pair(k, hehe);
        }
    }
    return {};
}