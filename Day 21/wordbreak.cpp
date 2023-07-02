//https://www.codingninjas.com/studio/problems/word-break_8230808?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(vector<string>& arr, int n, string& target) {
    // Create a set of words from the dictionary for efficient lookup
    unordered_set<string> wordSet(arr.begin(), arr.end());

    int len = target.length();

    // Create a dynamic programming table to store the subproblem results
    vector<bool> dp(len + 1, false);

    // Empty string is always considered valid
    dp[0] = true;

    // Iterate through the target string
    for (int i = 1; i <= len; i++) {
        // Check all possible substrings from the current position
        for (int j = i - 1; j >= 0; j--) {
            // If the previous substring is valid and the current substring is in the dictionary, mark it as valid
            if (dp[j] && wordSet.find(target.substr(j, i - j)) != wordSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    // Return the result for the entire target string
    return dp[len];
}


