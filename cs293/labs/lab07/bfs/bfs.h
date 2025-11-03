#ifndef BFS_H
#define BFS_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <algorithm>

class Graph
{
public:
    int V;                             // number of vertices
    std::vector<std::vector<int>> adj; // adjacency list

    Graph(int v, const std::vector<std::pair<int, int>> &edges);
};

// Performs BFS on graph g starting from node x.
// Returns a map where key = node, value = parent of node in BFS tree.
std::unordered_map<int, int> bfs(const Graph &g, int x);

// Returns the shortest walk that goes through the given list of stations in order.
std::vector<int> shortest_walk(const Graph &g, const std::vector<int> &stations);

#endif
