//https://www.codingninjas.com/studio/problems/matrix-median_8230735?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h>
using namespace std;

int getMedian(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    bool even;
    if ((row * col) % 2 == 0)
        even = true;
    else
        even = false;

    int size = (row * col) / 2 + 1;

    vector<int> ans;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> idx(row, 0);

    for (int i = 0; i < row; i++) {
        pq.push({matrix[i][idx[i]], i});
        idx[i]++;
    }

    while (size--) {
        int val = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        ans.push_back(val);

        if (idx[i] == col)
            continue;

        pq.push({matrix[i][idx[i]], i});
        idx[i]++;
    }

    int res = 0;

    if (even)
        res = (ans.back() + ans[ans.size() - 2]) / 2; // Corrected index for median calculation
    else
        res = ans.back();

    return res;
}
