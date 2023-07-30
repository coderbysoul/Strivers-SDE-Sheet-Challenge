//https://www.codingninjas.com/studio/problems/edit-distance_8230685?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>
int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1]) {
        return solve(i - 1, j - 1, s1, s2, dp);
    }
    return dp[i][j] = 1 + min({ solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp), solve(i - 1, j - 1, s1, s2, dp) });
}

int editDistance(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= m; i++)
        dp[0][i] = i;
    for (int j = 0; j <= n; j++)
        dp[j][0] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
    }

    return dp[n][m];
}
