#ifndef COMPARE_H
#define COMPARE_H

#include <vector>
#include <queue>


class GraphA 
{
	int V; // stores number of vertices
    std::vector<std::vector<int>> adj;
	
	public:
    		GraphA(int V);
    		
    		void addEdge(int u, int v);
    		
    		void bfs(int src, std::vector<int>& order) const;
    		
    		bool hasEdge(int u, int v) const; // for queries
};


class GraphM 
{
    	int V;
    	std::vector<std::vector<bool>> mat;
	
	public:
    		GraphM(int V);
    		
    		void addEdge(int u, int v);
    		
    		void bfs(int src, std::vector<int>& order) const;
    		
    		bool hasEdge(int u, int v) const; // for queries
};

#endif

