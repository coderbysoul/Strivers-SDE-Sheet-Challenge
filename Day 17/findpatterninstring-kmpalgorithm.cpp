//https://www.codingninjas.com/studio/problems/find-pattern-in-string-kmp-algorithm_8230819?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 
std::vector<int> generateLPS(const std::string& pattern) {
    int M = pattern.length();
    std::vector<int> lps(M, 0);

    int len = 0;
    int i = 1;

    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

bool findPattern(const std::string& p, const std::string& s) {
    int M = p.length();
    int N = s.length();

    std::vector<int> lps = generateLPS(p);

    int i = 0; // index for string 's'
    int j = 0; // index for pattern 'p'

    while (i < N) {
        if (p[j] == s[i]) {
            j++;
            i++;
        }

        if (j == M) {
            return true;
        } else if (i < N && p[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return false;
}