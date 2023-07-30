//https://www.codingninjas.com/studio/problems/dfs-traversal_8230690?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

using namespace std;

void dfs(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, vector<vector<int>>& ans, int node) {
    vector<int> temp;

    stack<int> s;
    s.push(node);
    visited[node] = true;

    while (!s.empty()) {
        int Top = s.top();
        s.pop();

        temp.push_back(Top);

        for (int i : adj[Top]) {
            if (!visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    ans.push_back(temp);
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> adj;
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    // Populating the adjacency list
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(adj, visited, ans, i);
        }
    }
    return ans;
}
