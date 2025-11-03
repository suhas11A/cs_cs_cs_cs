/***********************************************
       DO NOT MODIFY ANYTHING IN THIS FILE
***********************************************/

#include <iostream>
#include "is-cycle.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    int E;
    std::cin >> E;
    Graph g;
    for (int i = 0; i < E; i++) {
        int u, v;
        std::cin >> u >> v;
        g.addEdge(u, v);
    }
    bool result = g.isCyclePresent();
    if (result) {
        std::cout << "Cycle is present" << std::endl;
    } else {
        std::cout << "Cycle is not present" << std::endl;
    }
}
