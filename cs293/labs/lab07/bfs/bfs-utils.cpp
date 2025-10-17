#include "bfs.h"

Graph::Graph(int v, const std::vector<std::pair<int, int>> &edges) : V(v)
{
    adj.resize(V);
    for (auto [u, w] : edges)
    {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }
}
