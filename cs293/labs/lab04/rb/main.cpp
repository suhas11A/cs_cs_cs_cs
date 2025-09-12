#include "common.h"
#include "rb.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>

int main() {
	// int n;
    // if (!(std::cin >> n)) return 0;
    // std::vector<int> vals(n);
    // std::iota(vals.begin(), vals.end(), 1);
    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::shuffle(vals.begin(), vals.end(), gen);
    // RedBlackTree tree;
    // for (int x : vals) tree.insert(x);
    // return 0;
	
	RedBlackTree tree;
	int n;
	std::cin >> n;
	int a=0;
	while(n--) {
		a++;
		tree.insert(a);
	}
	tree.printRBT(tree.getRoot());
    return 0;
}