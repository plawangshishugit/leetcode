class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        // Base case: top of triangle
        if (i == 0 && j == 0)
            return triangle[0][0];
        // Invalid index (out of bounds)
        if (j < 0 || j > i)
            return 1e9;
        // Memoization check
        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursive relation
        int up = triangle[i][j] + f(i - 1, j - 1, triangle, dp);
        int upRight = triangle[i][j] + f(i - 1, j, triangle, dp);

        return dp[i][j] = min(up, upRight);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = INT_MAX;
        // Last row → choose min from all possible end positions
        for (int j = 0; j < triangle[n - 1].size(); j++) {
            mini = min(mini, f(n - 1, j, triangle, dp));
        }
        return mini;
    }
};
