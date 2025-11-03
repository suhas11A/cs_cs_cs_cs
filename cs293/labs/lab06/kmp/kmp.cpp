#include "kmp.h"

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(const std::string &pat, std::vector<int> &lps) {
    int m = pat.size();
    lps.assign(m+1, 0);
    lps[0] = -1;
    int i = 1;
    int j = 0;
    while (i < m) {
        if (pat[i]==pat[j]) lps[i] = lps[j];
        else {
            lps[i] = j;
            while (pat[i]!=pat[j] && j>0) j=lps[j];
        }
        i++; j++;
    }
    lps[m] = j;
}


// KMP search: returns vector of starting indices of pattern in text
std::vector<int> KMPSearch(const std::string &pat, const std::string &txt) {
    std::vector<int> res;
    if (pat.empty() || txt.empty() || pat.size() > txt.size()) return res;

    std::vector<int> lps;
    computeLPSArray(pat, lps);

    int i = 0; int j = 0;
    int n = txt.size(); int m = pat.size();

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                res.push_back(i-j);
                j = lps[j];
            }
        }
        else {
            j=lps[j];
            if (j<0) {i++;j++;}
        }
    }
    return res;
}
