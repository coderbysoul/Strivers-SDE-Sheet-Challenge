//https://www.codingninjas.com/studio/problems/prim-s-mst_8230809?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

std::vector<std::pair<std::pair<int, int>, int>> calculatePrimsMST(int n, int m, std::vector<std::pair<std::pair<int, int>, int>>& g) {
    std::vector<std::pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::vector<int> dist(n + 1, INT_MAX);
    std::vector<int> parent(n + 1, -1);
    std::vector<int> vis(n + 1, 0);

    pq.push({0, 1});
    dist[1] = 0;
    parent[1] = -1;

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;

        for (auto it : adj[node]) {
            int adjnode = it.first;
            int wt = it.second;

            if (!vis[adjnode] && dist[adjnode] > wt) {
                dist[adjnode] = wt;
                parent[adjnode] = node;
                pq.push({wt, adjnode});
            }
        }
    }

    std::vector<std::pair<std::pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++) {
        ans.push_back({{parent[i], i}, dist[i]});
    }

    return ans;
}
