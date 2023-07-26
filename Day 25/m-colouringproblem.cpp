//https://www.codingninjas.com/studio/problems/m-coloring-problem_8230777?challengeSlug=striver-sde-challenge
#include<bits/stdc++.h>

bool isSafe(int node, vector<vector<int>> &mat, vector<vector<int>> &color, int n, int col) {
    for (int k = 0; k < n; k++) {
        if (k != node && mat[k][node] == 1 && color[k][0] == col)
            return false;
    }
    return true;
}

bool solve(int node, vector<vector<int>> &mat, int m, vector<vector<int>> &color, int n) {
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, mat, color, n, i)) {
            color[node][0] = i;
            if (solve(node + 1, mat, m, color, n))
                return true;
            color[node][0] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<vector<int>> color(n, vector<int>(1, 0));

    if (solve(0, mat, m, color, n))
        return "YES";
    return "NO";
}
