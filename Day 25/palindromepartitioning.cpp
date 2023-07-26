//https://www.codingninjas.com/studio/problems/palindrome-partitioning_8230726?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void partitionHelper(string &s, int start, vector<string> &current, vector<vector<string>> &result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < s.length(); i++) {
        if (isPalindrome(s, start, i)) {
            current.push_back(s.substr(start, i - start + 1));
            partitionHelper(s, i + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(s, 0, current, result);
    return result;
}


