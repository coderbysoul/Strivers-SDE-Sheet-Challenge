//https://www.codingninjas.com/studio/problems/k-most-frequent-elements_8230853?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int>& arr) {
    unordered_map<int, int> mp;
    for (int x : arr)
        mp[x]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto x : mp) {
        pq.push({x.second, x.first});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
