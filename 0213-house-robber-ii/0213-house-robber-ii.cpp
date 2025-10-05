class Solution {
public:
    // helper function for linear house robber problem
    int houseRobber1(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> temp1, temp2;
        
        // case 1: exclude first house
        for(int i = 1; i < n; i++){
            temp1.push_back(nums[i]);
        }
        
        // case 2: exclude last house
        for(int i = 0; i < n-1; i++){
            temp2.push_back(nums[i]);
        }
        
        return max(houseRobber1(temp1), houseRobber1(temp2));
    }
};
