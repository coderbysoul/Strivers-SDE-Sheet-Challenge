//https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_8230844?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h> 
using namespace std;

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Create a 2D DP array to store the results of subproblems
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));

    // Base case: If the sum is 0, then an empty subset is possible
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the DP table using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            // If the current element is greater than the target sum, exclude it
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    // The result will be in dp[n][k]
    return dp[n][k];
}
