//https://www.codingninjas.com/studio/problems/kruskal-s-minimum-spanning-tree-algorithm_8230804?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int kruskalMST(int n, vector<vector<int>>& edges) {
    // Sort the edges in ascending order based on their weights
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });

    int mstWeight = 0;
    DisjointSet ds(n);

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // If adding the current edge does not form a cycle, include it in the MST
        if (ds.find(u) != ds.find(v)) {
            mstWeight += weight;
            ds.unionSets(u, v);
        }
    }

    return mstWeight;
}
