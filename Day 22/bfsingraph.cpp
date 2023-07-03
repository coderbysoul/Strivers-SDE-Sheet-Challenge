//https://stackoverflow.com/questions/76026843/androidexporeact-native-voice-voice-typeerror-cannot-read-property-sta

#include <bits/stdc++.h>
void BFSHelper(int start, vector<vector<int>>& adjList, vector<int>& vis, vector<int>& bfs) {
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        // Sort the adjacent nodes before pushing them into the queue
        sort(adjList[node].begin(), adjList[node].end());
        
        for (auto adjacent : adjList[node]) {
            if (!vis[adjacent]) {
                vis[adjacent] = 1;
                q.push(adjacent);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    vector<vector<int>> adjList(vertex);
    for (auto it : edges) {
        adjList[it.first].push_back(it.second);
        adjList[it.second].push_back(it.first);
    }

    vector<int> vis(vertex, 0);
    vector<int> bfs;
    
    for (int i = 0; i < vertex; i++) {
        if (!vis[i]) {
            BFSHelper(i, adjList, vis, bfs);
        }
    }
    
    return bfs;
}
