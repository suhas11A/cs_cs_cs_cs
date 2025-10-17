#include "bfs.h"


std::unordered_map<int, int> bfs(const Graph &g, int x) {
    std::queue<int> que;
    bool visited[g.V];
    for (int i=0;i<g.V;i++) visited[i] = false;
    std::unordered_map<int, int> ans;
    que.push(x);
    visited[x] = true;
    ans[x] = -1;
    while (!que.empty()) {
        int now = que.front(); que.pop();
        for (int a : g.adj[now]) {
            if (!visited[a]) {
                visited[a] = true;
                que.push(a);
                ans[a] = now;
            }
        }
    }
    return ans;
}

std::vector<int> shortest_path_between(const Graph& g, int src, int dest) {
    std::vector<int> fake_ans;
    auto mapiee = bfs(g, src);
    while(dest!=src) {
        dest = mapiee[dest];
        fake_ans.push_back(dest);
    }
    std::reverse(fake_ans.begin(), fake_ans.end());
    return fake_ans;
}

std::vector<int> shortest_walk(const Graph &g, const std::vector<int> &stations) {
    std::vector<int> ans;
    int lenn = stations.size();
    if (lenn<2) return {};
    for (int i=0;i<lenn-1;i++) {
        int src = stations[i];
        int dest = stations[i+1];
        auto tempo = shortest_path_between(g,src, dest);
        ans.insert(ans.end(), tempo.begin(), tempo.end());
    }
    ans.push_back(stations[lenn-1]);
    return ans;
}
