class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Any sum = 0 can always be formed by taking empty subset
        for (int i = 0; i < n; i++) dp[i][0] = true;

        // Base case: first element
        if (arr[0] <= sum) dp[0][arr[0]] = true;

        // Fill dp
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {
                bool notTake = dp[i - 1][target];
                bool take = false;
                if (arr[i] <= target) take = dp[i - 1][target - arr[i]];
                dp[i][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }
};
