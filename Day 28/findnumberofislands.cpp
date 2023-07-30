//https://www.codingninjas.com/studio/problems/find-number-of-islands_8230692?challengeSlug=striver-sde-challenge&leftPanelTab=1

void DFS(int** arr, int n, int m, int row, int col) {
    // Check if the current position is within the grid boundaries and represents land
    if (row < 0 || col < 0 || row >= n || col >= m || arr[row][col] != 1)
        return;

    // Mark the current position as visited (by changing it to water or any other value)
    arr[row][col] = 0;

    // Define all eight possible directions
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Recursively perform DFS in all eight adjacent directions
    for (int i = 0; i < 8; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];
        DFS(arr, n, m, newRow, newCol);
    }
}
int getTotalIslands(int** arr, int n, int m) {
    int count = 0;

    // Traverse each cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell represents land, perform DFS to explore the island
            if (arr[i][j] == 1) {
                count++;
                DFS(arr, n, m, i, j);
            }
        }
    }

    return count;
}
