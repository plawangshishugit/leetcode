class Solution {
public:
    int solve(int i, vector<int>& nums) {
        // base cases
        if (i < 0) return 0;
        if (i == 0) return nums[0];

        // choice: rob current or skip
        int rob = nums[i] + solve(i-2, nums);
        int skip = solve(i-1, nums);

        return max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(n-1, nums);
    }
};
