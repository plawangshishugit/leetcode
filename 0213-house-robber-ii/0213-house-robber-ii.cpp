class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if (i < 0) return 0;
        if (i == 0) return nums[0];

        if (dp[i] != -1) return dp[i];

        int rob = nums[i] + solve(i-2, nums, dp);
        int skip = solve(i-1, nums, dp);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // special case

        // case 1: exclude first house
        vector<int> temp1(nums.begin() + 1, nums.end());
        vector<int> dp1(temp1.size(), -1);
        int case1 = solve(temp1.size() - 1, temp1, dp1);

        // case 2: exclude last house
        vector<int> temp2(nums.begin(), nums.end() - 1);
        vector<int> dp2(temp2.size(), -1);
        int case2 = solve(temp2.size() - 1, temp2, dp2);

        return max(case1, case2);
    }
};
