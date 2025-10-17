#include <iostream>
#include <vector>
#include "isHeap.h"


using namespace std;


int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        freopen(argv[1], "r", stdin);
    }


    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    bool result = isMaxHeap(arr);
    cout << (result ? "YES" : "NO") << '\n';

    return 0;
}