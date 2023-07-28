//https://www.codingninjas.com/studio/problems/rotting-oranges_8230701?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m) {
    vector<pair<int, int>> help = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
            }
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans = 0;

    while (!q.empty()) {
        pair<pair<int, int>, int> node = q.front();
        q.pop();
        int x = node.first.first;
        int y = node.first.second;
        int time = node.second;
        ans = time;
        visited[x][y] = 1;
        int new_time = time + 1;

        for (int i = 0; i < 4; i++) {
            int new_x = help[i].first + x;
            int new_y = help[i].second + y;

            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m && grid[new_x][new_y] == 1 && visited[new_x][new_y] != 1) {
                grid[new_x][new_y] = 2;
                pair<pair<int, int>, int> l = {{new_x, new_y}, new_time};
                q.push(l);
            }

            if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m) {
                visited[new_x][new_y] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return ans;
}
