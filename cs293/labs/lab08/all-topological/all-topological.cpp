#include <iostream>
#include <fstream>
#include "all-topological.h"

using namespace std;
// TO-DO STARTS

//Constructor for the graph
Graph::Graph(int V)
{
}


//function to add a directed edge
//need to add edge from v to w
void Graph::addEdge(int v, int w)
{
}

//print the sorted vector that stores the current topological sort
void Graph::report_a_sorted_order()
{
}

//print -1 if a cycle is found
//should be printed only once
void Graph::report_failed_to_sort()
{
}

//traverse through the graph to find all possible topological sorts
//recursively calls itself
//use the above two functions to print
void Graph::alltopologicalSort()
{
}

//TO-DO ENDS

void Graph::dump_dot()
{
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
