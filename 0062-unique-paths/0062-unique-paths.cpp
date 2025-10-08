class Solution {
public:
    int f(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0) return 1;

        if (dp[m][n] != -1) return dp[m][n];

        int right = f(m, n - 1, dp);
        int down = f(m - 1, n, dp);

        return dp[m][n] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(m-1, n-1, dp);
    }
};
