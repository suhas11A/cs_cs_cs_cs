#include "autocomplete.h"

void preprocessDictionary(std::vector<std::string>& dict, std::vector<int>& freq) {
    // This function can be used to preprocess the dictionary
    // This is not needed for naiive implementation, but think how it can help in more efficient implementations
    // This function will be called once before any calls to autocomplete queries
    // Advice : Don't bother too much about this at first, try to get the basic version working first
    //          This function is not part of the evaluation. You may get some reward for efficient
    //          implementation.
}

bool check_prefix(std::string a, std::string b) {
    int len = a.size();
    if ((int) b.size()<len) return false;
    for (int i=0;i<len;i++) {
        if (a[i]!=b[i]) return false;
    }
    return true;
}


// NOTE: All dictionary words and prefixes are guaranteed lowercase.
// TODO: Implement computePrefixMatches
// Return indices of dictionary words that start with the given prefix
std::vector<int> computePrefixMatches(const std::vector<std::string>& dict,
                                      const std::string& prefix) {
    std::vector<int> ans;
    int len = dict.size();
    for (int i=0;i<len;i++) {
        if (check_prefix(prefix, dict[i])) ans.push_back(i);
    }
    return ans;
}

// TODO: Implement pickTopK
// Pick top K indices based on frequency (descending) and lexicographic order (ascending) tie-breaker
// Return up to K indices from 'indices' sorted by freq and lexicographically
std::vector<int> pickTopK(const std::vector<int>& indices,
                          const std::vector<std::string>& dict,
                          const std::vector<int>& freq,
                          int K) {
    if (K==0 || indices.size()==0) return {};
    std::vector<std::pair<int, std::string>> order1;
    std::map<std::string, int> order2;
    int tempopo = indices.size();
    for (int j=0;j<tempopo;j++) {
        int i = indices[tempopo-j-1];
        order1.push_back(make_pair(-freq[i], dict[i]));
        order2[dict[i]]=i;
    }
    std::sort(order1.begin(), order1.end());
    std::vector<int> myans;
    for (auto i : order1) {
        myans.push_back(order2[i.second]);
    }
    int my_size = myans.size();
    std::vector<int> ans;
    for (int i=0;((i<my_size) & (i<K));i++) {
        ans.push_back(myans[i]);
    }
    return ans;
}

// TODO: Implement autocomplete using helpers
// Produce up to K autocomplete suggestions for a prefix
// Use computePrefixMatches and pickTopK functions
std::vector<std::string> autocomplete(const std::vector<std::string>& dict,
                                      const std::vector<int>& freq,
                                      const std::string& prefix,
                                      int K) {
    auto a = computePrefixMatches(dict, prefix);
    auto b = pickTopK(a, dict, freq, K);
    std::vector<std::string> olala;
    for (auto i : b) {
        olala.push_back(dict[i]);
    }
    return olala;
}
