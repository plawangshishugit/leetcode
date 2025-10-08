class Solution {
public:
    int f(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        // Out of bounds
        if (m < 0 || n < 0) return 0;

        // If obstacle found
        if (obstacleGrid[m][n] == 1) return 0;

        // If at starting cell (0,0)
        if (m == 0 && n == 0) return 1;

        // Memoization check
        if (dp[m][n] != -1) return dp[m][n];

        // Move left and up (since we are going backward)
        int left = f(m, n - 1, obstacleGrid, dp);
        int up = f(m - 1, n, obstacleGrid, dp);

        return dp[m][n] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // If start or destination is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, obstacleGrid, dp);
    }
};
