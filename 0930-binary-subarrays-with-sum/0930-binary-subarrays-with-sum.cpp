class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>mp;
        int ans = 0; 
        int sum = 0;
        mp.insert({0,1});
        for(int i =0; i<nums.size(); i++){
            sum += nums[i];
            if(mp.find(sum-goal) != mp.end()){
                ans += mp[sum - goal];
            }
            mp[sum] ++;
        }
        return ans;
    }
};