//https://www.codingninjas.com/studio/problems/rod-cutting-problem_8230727?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <vector>
#include <algorithm>

int cutRod(vector<int> &price, int n) {
    // Create a vector to store the maximum revenue for each rod length from 0 to n
    vector<int> dp(n + 1, 0);

    // Solve the problem using bottom-up dynamic programming
    for (int i = 1; i <= n; i++) {
        int maxRevenue = INT_MIN;
        for (int j = 1; j <= i; j++) {
            maxRevenue = max(maxRevenue, price[j - 1] + dp[i - j]);
        }
        dp[i] = maxRevenue;
    }

    // The maximum revenue for rod of length n will be stored in dp[n]
    return dp[n];
}
