class Solution {
public:
    int atMostK(vector<int>&nums, int k){
        int low = 0; int cnt = 0; 
        unordered_map<int, int>mp;
        for(int high = 0; high <nums.size(); high ++){
            mp[nums[high]]++;
            while(mp.size()> k){
                mp[nums[low]]--;
                if(mp[nums[low]] == 0){
                    mp.erase(nums[low]);
                }
                low ++;
            }
            cnt  = cnt + (high - low + 1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums,k) - atMostK(nums, k-1);
    }
};