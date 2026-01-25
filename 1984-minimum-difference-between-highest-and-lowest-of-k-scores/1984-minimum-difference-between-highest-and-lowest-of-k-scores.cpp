class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        for(int i = 0; i+k-1<n; i++){
            mindiff = min(mindiff, nums[i + k - 1] - nums[i]);
        }
        return mindiff;
    }
};