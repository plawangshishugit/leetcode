class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        for(int i = 0; i<n-1; i++){
            int diff = abs(nums[i] - nums[i+1]);
            if(diff<mindiff){
                mindiff = diff;
            }
        }
        return mindiff;
    }
};