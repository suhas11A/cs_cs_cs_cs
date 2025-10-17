#include "common.h"

int main(int argc, char** argv) {
    if (argc > 1) {
        if (freopen(argv[1], "r", stdin) == nullptr) // cin redirects to file argv[1]
        {
            std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int mode;
    std::cin >> mode;  // 0 = solve, 1 = verify

    int n, m;
    std::cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        G.add_edge(u, v);
    }

    if (mode == 1) {
        // -------------------- VERIFY MODE --------------------
        int t;
        std::cin >> t;
        std::vector<int> schedule(t);
        for (int i = 0; i < t; ++i) std::cin >> schedule[i];
        bool ok = verify_burning(G, schedule);
        std::cout << (ok ? "YES\n" : "NO\n");
    } 
    else if (mode == 0) {
        // -------------------- SOLVE MODE --------------------
        auto [t_min, schedule] = brute_force_burning(G);
        std::cout << t_min << "\n";
        for (int i = 0; i < (int)schedule.size(); ++i) {
            if (i) std::cout << " ";
            std::cout << schedule[i];
        }
        std::cout << "\n";
    } 
    else {
        std::cerr << "Invalid mode. Use 0=solve or 1=verify.\n";
        return 1;
    }

    return 0;
}
