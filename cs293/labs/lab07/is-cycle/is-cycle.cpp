#include "is-cycle.h"

// Implement this function to check if there is a cycle present in the graph
bool Graph::isCyclePresent(){
    int n=0; std::vector<int> nodie;
    for (auto tempo : nodes) {
        n++;
        nodie.push_back(tempo.first);
    }
    std::map<int,int> n_to_nodes;
    for (int i=0;i<n;i++) {
        n_to_nodes[nodie[i]] = i;
    }
    if (n==0) return false;
    std::queue<int> que;
    bool visited[n]; for (int i=0;i<n;i++) visited[i] = false;
    int depth[n]; for (int i=0;i<n;i++) depth[i] = -2;
    std::map<int,int> parent;
    bool all_covered = false;
    int now = 0;
    while (!all_covered) {
        int ver = nodie[now];
        parent[n_to_nodes[ver]] = -1;
        depth[n_to_nodes[ver]] = 0;
        visited[n_to_nodes[ver]] = true;
        que.push(ver);
        while (!que.empty()) {
            int now = que.front(); que.pop();
            for (auto a : (nodes[now]->adj)) {
                if (!visited[n_to_nodes[a]]) {
                    visited[n_to_nodes[a]] = true;
                    parent[n_to_nodes[a]] = now;
                    depth[n_to_nodes[a]] = depth[n_to_nodes[now]]+1;
                    que.push(a);
                }
            }
        }
        for (int i=now;i<n;i++) {
            now = -1;
            if (!visited[i]) {
                now = i;
                break;
            }
        }
        if (now==-1) all_covered=true;
    }
    for (auto tempo : nodes) {
        int node = tempo.first;
        GraphNode* pointer = tempo.second;
        for (int a : pointer->adj) {
            if (depth[n_to_nodes[a]]==depth[n_to_nodes[node]]) return true;
            if (depth[n_to_nodes[a]]==depth[n_to_nodes[node]]+1) {
                if (parent[n_to_nodes[a]]!=node) return true;
            }
            else if (depth[n_to_nodes[node]]==depth[n_to_nodes[a]]+1){
                if (parent[n_to_nodes[node]]!=a) return true;
            }
        }
    }
    return false;
}