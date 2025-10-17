#include "autocomplete.h"

void preprocessDictionary(std::vector<std::string>& dict, std::vector<int>& freq) {
    // This function can be used to preprocess the dictionary if needed.
    // This is not needed for naiive implementation, but think how it can help in more efficient implementations
    // This function will be called once before any calls to autocomplete queries

}



std::vector<int> computePrefixMatches(const std::vector<std::string>& dict,
                                      const std::string& prefix)
{
    std::vector<int> res;
    if (prefix.empty())
    {
        res.reserve(dict.size());
        for (int i = 0; i < (int)dict.size(); ++i) res.push_back(i);
        return res;
    }
    for (int i = 0; i < (int)dict.size(); ++i)
    {
        const std::string& w = dict[i];
        if (w.size() >= prefix.size() && w.compare(0, prefix.size(), prefix) == 0) res.push_back(i);
    }
    return res;
}

std::vector<int> pickTopK(const std::vector<int>& indices,
                          const std::vector<std::string>& dict,
                          const std::vector<int>& freq,
                          int K)
{
    if (K <= 0) return {};
    std::vector<int> v = indices;
    std::sort(v.begin(), v.end(), [&](int a, int b){
        if (freq[a] != freq[b]) return freq[a] > freq[b];
        if (dict[a] != dict[b]) return dict[a] < dict[b];
        return a < b;
    });
    if ((int)v.size() > K) v.resize(K);
    return v;
}

std::vector<std::string> autocomplete(const std::vector<std::string>& dict,
                                      const std::vector<int>& freq,
                                      const std::string& prefix,
                                      int K)
{
    if (K == 0) return {};
    auto matches = computePrefixMatches(dict, prefix);
    if (matches.empty()) return {};
    auto chosen = pickTopK(matches, dict, freq, K);
    std::vector<std::string> out; out.reserve(chosen.size());
    for (int idx : chosen) out.push_back(dict[idx]);
    return out;
}
