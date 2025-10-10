class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix.back(); // start from last row
        
        for (int i = n - 2; i >= 0; i--) {
            vector<int> new_dp(n);
            for (int j = 0; j < n; j++) {
                int down = dp[j];
                int left_diag = (j > 0) ? dp[j - 1] : INT_MAX;
                int right_diag = (j < n - 1) ? dp[j + 1] : INT_MAX;
                new_dp[j] = matrix[i][j] + min({down, left_diag, right_diag});
            }
            dp = new_dp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
