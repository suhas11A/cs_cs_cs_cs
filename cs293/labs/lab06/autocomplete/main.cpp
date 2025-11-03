#include <iostream>
#include <vector>
#include <string>
#include "autocomplete.h"

using namespace std;

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        if (freopen(argv[1], "r", stdin) == nullptr)
        {
            cerr << "Error: Could not open input file " << argv[1] << std::endl;
            return 1;
        }
    }

    int n; 
    if (!(cin >> n)) return 0;
    vector<string> dict(n);
    for (int i = 0; i < n; ++i) cin >> dict[i];
    vector<int> freq(n);
    for (int i = 0; i < n; ++i) cin >> freq[i];
    preprocessDictionary(dict, freq);
    int Q; cin >> Q; // number of queries
    while (Q--) {
        string prefix; int K; 
        cin >> prefix >> K;
        auto suggestions = autocomplete(dict, freq, prefix, K);
        if (suggestions.empty())
        {
            cout << "-\n";
        }
        else
        {
            for (size_t i = 0; i < suggestions.size(); ++i)
            {
                if (i) cout << ' ';
                cout << suggestions[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
