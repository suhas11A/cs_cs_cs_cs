#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <algorithm>
#include <bits/stdc++.h>


void preprocessDictionary(std::vector<std::string>& dict, std::vector<int>& freq);

// All words and prefixes are guaranteed lowercase.
// Return indices of dictionary words that start with the given prefix.
std::vector<int> computePrefixMatches(const std::vector<std::string>& dict,
                                      const std::string& prefix);

// Pick top K indices based on frequency (descending) and lexicographic order (ascending) tie-breaker.
std::vector<int> pickTopK(const std::vector<int>& indices,
                          const std::vector<std::string>& dict,
                          const std::vector<int>& freq,
                          int K);

// Produce up to K autocomplete suggestions for a prefix.
std::vector<std::string> autocomplete(const std::vector<std::string>& dict,
                                      const std::vector<int>& freq,
                                      const std::string& prefix,
                                      int K);

#endif // AUTOCOMPLETE_H
