//https://www.codingninjas.com/studio/problems/z-algorithm_8230818?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>


vector<int> calculateZ(string& s) {
    int n = s.length();
    vector<int> Z(n, 0);

    int left = 0, right = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= right)
            Z[i] = std::min(right - i + 1, Z[i - left]);

        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
            ++Z[i];

        if (i + Z[i] - 1 > right) {
            left = i;
            right = i + Z[i] - 1;
        }
    }

    return Z;
}

int zAlgorithm(string& s, string& p, int n,int m) {
   string concat = p + "#" + s;
    int pLength = p.length();
    int concatLength = concat.length();

    vector<int> Z = calculateZ(concat);

    int count = 0;
    for (int i = pLength + 1; i < concatLength; ++i) {
        if (Z[i] == pLength)
            ++count;
    }

    return count;
}
