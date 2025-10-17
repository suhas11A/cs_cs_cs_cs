#pragma once
#include <vector>
#include <set>
#include <iostream>

struct Graph {
    int n; // number of vertices
    std::vector<std::vector<int>> adj;

    Graph(int n);
    void add_edge(int u, int v);
};

// Verifier: check if a given burning schedule burns all vertices within t steps
bool verify_burning(const Graph& G, const std::vector<int>& schedule);

// Brute-force exact solver: tries all schedules (exponential), returns minimal t and one optimal schedule
std::pair<int, std::vector<int>> brute_force_burning(const Graph& G);
