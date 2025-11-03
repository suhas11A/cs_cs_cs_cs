#include <iostream>
#include <fstream>
#include <functional>
#include "all-topological.h"

using namespace std;
// TO-DO STARTS

//Constructor for the graph
Graph::Graph(int V) {
	adj = new list<int>[V];
    indegree.assign(V, 0);
    visited = new bool[V];
    for (int i = 0; i < V; ++i) visited[i] = false;
    sorted.clear();
    found_cycle = false;
}


//function to add a directed edge
//need to add edge from v to w
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    indegree[w]++;
}

//print the sorted vector that stores the current topological sort
void Graph::report_a_sorted_order() {
    for (size_t i = 0; i < sorted.size(); ++i) {
        if (i) cout << " ";
        cout << (sorted[i] + 1);
    }
    cout << "\n";
}

//print -1 if a cycle is found
//should be printed only once
void Graph::report_failed_to_sort() {
    static bool printed = false;
    if (!printed) {
        cout << -1 << "\n";
        printed = true;
    }
}

//traverse through the graph to find all possible topological sorts
//recursively calls itself
//use the above two functions to print
void Graph::alltopologicalSort() {
    function<void()> dfs = [&]() {
        bool progressed = false;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && indegree[v] == 0) {
                progressed = true;

                visited[v] = true;
                sorted.push_back(v);

                vector<int> changed;
                for (int w : adj[v]) {
                    indegree[w]--;
                    changed.push_back(w);
                }

                dfs();

                for (int w : changed) indegree[w]++;
                sorted.pop_back();
                visited[v] = false;
            }
        }

        if (!progressed) {
            if ((int)sorted.size() == V) {
                report_a_sorted_order();
            } else {
                found_cycle = true;
            }
        }
    };

    dfs();

    if (found_cycle) {
        report_failed_to_sort();
    }
}

//TO-DO ENDS

void Graph::dump_dot() {
	ofstream output("g.dot");
	output << "digraph graphname {\n";
	for(int v = 0; v < V; v++)
	{
		for(auto w : adj[v])
		{
			output << v + 1 << "->" << w + 1 << "\n";
		}
	}
	output << "}\n";
	output.close();
}
