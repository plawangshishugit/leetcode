class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle.back()); // start from last row

        // Move upward from second last row to top
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        // The top element now contains the minimum total
        return dp[0];
    }
};
