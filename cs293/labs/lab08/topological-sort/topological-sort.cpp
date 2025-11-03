#include "topological-sort.h"
#include <algorithm>

void dfs(const Graph &g,int node,std::vector<int> &vis,std::vector<int> &arr,std::vector<std::pair<int,int>> &dep,int& time) {
    vis[node]=true;
    arr[node]=time++;
    int ola = g.adj[node].size();
    for(int i=0;i<ola;i++){
        if(!vis[g.adj[node][i]]){
            dfs(g,g.adj[node][i],vis,arr,dep,time);
        }
    }
    dep[node]=std::make_pair(time++, node);
}



std::vector<int> topologicalSort(const Graph &graph) {
    int v=graph.V;
    std::vector<int> vis(v,0);
    std::vector<int> arrive(v,0);
    std::vector<std::pair<int,int>> depart(v,std::make_pair(0,0));
    int time=0;
    for (int i=0;i<v;i++) {
        if (!vis[i]) dfs(graph,i,vis,arrive,depart,time);
    }
  
    for(int i=0;i<v;i++){
        int ola = graph.adj[i].size();
        for(int j=0;j<ola;j++){
            if(depart[i].first<=depart[graph.adj[i][j]].first){
                return {};
            }
        }
    }

    std::sort(depart.begin(),depart.end()); 
    std::vector<int> result(v);
    for(int i=0;i<v;i++){
        result[i]=depart[v-i-1].second;
    }
    return result;
}