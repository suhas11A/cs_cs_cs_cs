#include <bits/stdc++.h>
#include "compare.h"
using namespace std;

using Clock = chrono::high_resolution_clock;

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    	
    	ios::sync_with_stdio(false);
    	cin.tie(nullptr);

    	int V, E;
    	cin >> V >> E;

    	GraphA gA(V);
    	GraphM gM(V);

    	for (int i = 0; i < E; i++) 
    	{
        	int u, v;
        	cin >> u >> v;
        	u--; v--; // convert to 0-based
        	gA.addEdge(u, v);
        	gM.addEdge(u, v);
    	}

    	int src;
    	cin >> src;
    	src--; // 0-based

    	int M;
    	cin >> M;
    	vector<pair<int, int>> queries(M);
    	for (int i = 0; i < M; i++) 
    	{
        	int u, v;
        	cin >> u >> v;
        	u--; v--; // 0-based
        	queries[i] = {u, v};
    	}

    	vector<int> orderA, orderM;

    	// BFS adjacency list
    	auto startA = Clock::now();
    	gA.bfs(src, orderA);
    	auto endA = Clock::now();
    	auto bfs_timeA = chrono::duration_cast<chrono::nanoseconds>(endA - startA).count();

    	// BFS adjacency matrix
    	auto startM = Clock::now();
    	gM.bfs(src, orderM);
    	auto endM = Clock::now();
    	auto bfs_timeM = chrono::duration_cast<chrono::nanoseconds>(endM - startM).count();

    	// Output BFS orders (1-based)
    	for (int v : orderA)
    	{ 
    		cout << v+1 << " ";
    	}
    	cout << "\n";
    	
    	for (int v : orderM) 
    	{
    		cout << v+1 << " ";
    	}
    	cout << "\n";

    	// Process queries
    	for (auto [u, v] : queries) 
    	{
        	auto qstartA = Clock::now();
        	bool existsA = gA.hasEdge(u, v);
        	auto qendA = Clock::now();
        	auto qtimeA = chrono::duration_cast<chrono::nanoseconds>(qendA - qstartA).count();

        	auto qstartM = Clock::now();
        	bool existsM = gM.hasEdge(u, v);
        	auto qendM = Clock::now();
        	auto qtimeM = chrono::duration_cast<chrono::nanoseconds>(qendM - qstartM).count();

        	// Output yes/no for file
        	cout << ((existsA && existsM) ? "yes" : "no") << "\n";

        	// Print per-query timings to terminal
        	cerr << "Query (" << u+1 << "," << v+1 << "): "<< "AdjList=" << qtimeA << "ns, "<< "AdjMatrix=" << qtimeM << "ns\n";
    	}

    	// Print BFS timings to terminal
    	cerr << "BFS Adjacency List Time: " << bfs_timeA << " ns\n";
    	cerr << "BFS Adjacency Matrix Time: " << bfs_timeM << " ns\n";

    	return 0;
}

