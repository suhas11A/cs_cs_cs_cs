#include "common.h"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    int part;
    std::cin >> part;

    int no_of_vertices, no_of_edges;
    std::cin >> no_of_vertices >> no_of_edges;

    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < no_of_edges; i++)
    {
        int u, v;
        std::cin >> u >> v;
        edges.emplace_back(u, v);
    }

    Graph g(no_of_vertices, edges);

    if (part == 1)
    {
        int source;
        std::cin >> source;

        std::unordered_map<int, int> parent = bfs(g, source);
        for (int i = 0; i < no_of_vertices; i++)
        {
            std::cout << parent[i] << "\n";
        }
    }
    else if (part == 2)
    {
        int no_of_stations;
        std::cin >> no_of_stations;

        std::vector<int> stations(no_of_stations);
        for (int i = 0; i < no_of_stations; i++)
        {
            std::cin >> stations[i];
        }

        std::vector<int> path = shortest_walk(g, stations);
        for (size_t i = 0; i < path.size(); ++i)
        {
            std::cout << path[i] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
