#include "topological-sort.h"
#include <algorithm>


// bool topologicalSortDFSHelper(const Graph &graph, int node,
//                               std::vector<bool> &visited,
//                               std::vector<bool> &recStack,
//                               std::vector<int> &result)
// {
// }

void dfs(const Graph &g,int node,std::vector<int> &vis,std::vector<int> &arr,std::vector<int> &dep,int& time){
  vis[node]=1;
  time++;
  arr[node]=time;
  for(int i=0;i<g.adj[node].size();i++){
    if(vis[g.adj[node][i]]!=1){
      dfs(g,g.adj[node][i],vis,arr,dep,time);
    }
  }
  time++;
  dep[node]=time;
}



std::vector<int> topologicalSort(const Graph &graph)
{
  //Implement here, You can use the above helper function for DFS calls and checking cycle
  //If you want you can modify the above helper function "topologicalSortDFSHelper" definition
  int v=graph.V;
  std::vector<int> vis(v,0);
  int time=0;
  std::vector arrive(v,0);
  std::vector depart(v,0);
  dfs(graph,0,vis,arrive,depart,time);
  while(true){
    int s=vis[1];
    int l=1;
    while(s!=0 && l<=v){
      s=vis[l];
      l++;
    }
    if(l==v-1){
      break;
    }
    dfs(graph,l,vis,arrive,depart,time);
  }
  
  for(int i=0;i<v;i++){
    for(int j=0;j<graph.adj[i].size();j++){
      if(depart[i]<=depart[graph.adj[i][j]]){
        return {};
      }
    }
  }

  std::vector<int> blah(time+2);
  for(int i=0;i<v;i++){
    blah[depart[i]]=i;
  }
  std::sort(depart.begin(),depart.end()); 
  std::vector<int> result(v);
  for(int i=0;i<v;i++){
    result[i]=blah[depart[v-i-1]];
  }
  return result;
}