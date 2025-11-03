#include <iostream>
#include <vector>
#include <set>

// ==== your function ====
std::vector<std::vector<int>> generate(int n,int k) {
    if (k==0) return {{}};
    auto tempo = generate(n, k-1);
    std::vector<std::vector<int>> ans;
    for (auto k_1 : tempo) {
        std::vector<bool> visited(n+1, false);
        for (auto i : k_1) visited[i] = true;
        std::set<int> remaining;
        for (int i=1;i<=n;i++) {
            if (!visited[i]) remaining.insert(i);
        }
        for (int i : remaining) {
            auto my_temp = k_1;
            my_temp.push_back(i);
            ans.push_back(my_temp);
        }
    }
    return ans;
}
// =======================

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    if (!(std::cin >> n >> k)) {
        std::cerr << "Usage: provide n and k on stdin (e.g., \"3 2\")\n";
        return 1;
    }

    auto res = generate(n, k);

    std::cout << "count = " << res.size() << "\n";
    for (const auto& v : res) {
        std::cout << "[";
        for (size_t i = 0; i < v.size(); ++i) {
            if (i) std::cout << " ";
            std::cout << v[i];
        }
        std::cout << "]\n";
    }
    return 0;
}
