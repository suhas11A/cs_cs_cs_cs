// ----------------------------
//       DO NOT MODIFY
// ----------------------------

#include <iostream>
#include "island-count.h"


int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    
    // input matrix
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> M(n, std::vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> M[i][j];
        }
    }
	std::cout << "Number of islands is: " << countIslands(M) << std::endl;
}
