#include "common.h"
#include <queue>


// The function that returns
// the minimum cost to connect n
// ropes of lengths stored in len[0..n-1]
int minCost(int len[], int n) {
    int cost = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; ++i) pq.push(len[i]);
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int s = a + b;
        cost += s;
        pq.push(s);
    }
    return cost;
}

