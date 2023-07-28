//https://www.codingninjas.com/studio/problems/rat-in-a-maze-all-paths_8230705?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include<bits/stdc++.h>

void help(int i, int j, int n, vector<vector<int>>& maze,
          vector<vector<int>>& visited, vector<vector<int>>& ans)
{
    if (i < 0 || j < 0 || i >= n || j >= n || maze[i][j] == 0)
        return;

    else if (i == n - 1 && j == n - 1)
    {
        vector<int> temp;
        visited[i][j] = 1;
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                temp.push_back(visited[k][l]);
            }
        }
        visited[i][j] = 0;
        ans.push_back(temp);
        return;
    }

    else
    {
        maze[i][j] = 0;

        // Down
        visited[i][j] = 1;
        help(i + 1, j, n, maze, visited, ans);
        visited[i][j] = 0;

        // Left
        visited[i][j] = 1;
        help(i, j - 1, n, maze, visited, ans);
        visited[i][j] = 0;

        // Right
        visited[i][j] = 1;
        help(i, j + 1, n, maze, visited, ans);
        visited[i][j] = 0;

        // Up
        visited[i][j] = 1;
        help(i - 1, j, n, maze, visited, ans);
        visited[i][j] = 0;

        maze[i][j] = 1;
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int>>& maze, int n)
{
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    help(0, 0, n, maze, visited, ans);
    return ans;
}
