class Solution {
public:
    int rows, cols;
int dfs(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    if (j1 < 0 || j1 >= cols || j2 < 0 || j2 >= cols) return INT_MIN;
    
    if (i == rows - 1) {
        if (j1 == j2) return grid[i][j1];      // ✅ grid is 2D
        else return grid[i][j1] + grid[i][j2];
    }

    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int maxCherries = 0;
    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
            val += dfs(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            maxCherries = max(maxCherries, val);
        }
    }

    return dp[i][j1][j2] = maxCherries;
}

    
    int cherryPickup(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        return dfs(0, 0, cols - 1, grid, dp);
    }
};
