#include "compare.h"

using namespace std;

// Constructor to initialize the feilds
GraphA::GraphA(int V) {
    this->V = V;
    adj.resize(V);
}


// Method to add an edge to the graph
// Takes two vertices as input
void GraphA::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    return;
}


// BFS traversal of the graph
// The bfs traversal order will be stored in the 'order' vector passed by reference to the function from main.
// So you do not need to create a temporary vector or return any vector back to main
void GraphA::bfs(int src, vector<int>& order) const {
    std::queue<int> que;
    bool visited[V];
    for (int i=0;i<V;i++) visited[i] = false;
    que.push(src);
    visited[src] = true;
    order.push_back(src);
    while (!que.empty()) {
        int now = que.front(); que.pop();
        for (int a : adj[now]) {
            if (!visited[a]) {
                visited[a] = true;
                order.push_back(a);
                que.push(a);
            }
        }
    }
}


// Method to check if an edge exists between vertex u and vertex v
bool GraphA::hasEdge(int u, int v) const {   
    for (auto tempo : adj[u]) {
        if (tempo==v) return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////

// Constructor to initialize the feilds
GraphM::GraphM(int V) {
    this->V = V;
    mat.resize(V);
    for (int i = 0; i < V; i++) mat[i].resize(V,false);   
}


// Method to add an edge to the graph
// Takes two vertices as input
void GraphM::addEdge(int u, int v) {
    mat[u][v] = true;
    mat[v][u] = true;
    return;
}


// BFS traversal of the graph
// The bfs traversal order will be stored in the 'order' vector passed by reference to the function from main.
// So you do not need to create a temporary vector or return any vector back to main
void GraphM::bfs(int src, vector<int>& order) const {
    std::queue<int> que;
    bool visited[V];
    for (int i=0;i<V;i++) visited[i] = false;
    que.push(src);
    visited[src] = true;
    order.push_back(src);
    while (!que.empty()) {
        int now = que.front(); que.pop();
        for (int a=0;a<V;a++) {
            if (!mat[now][a]) continue;
            if (!visited[a]) {
                visited[a] = true;
                order.push_back(a);
                que.push(a);
            }
        }
    }
}


// Method to check if an edge exists between vertex u and vertex v
bool GraphM::hasEdge(int u, int v) const {
    return mat[u][v];
}

