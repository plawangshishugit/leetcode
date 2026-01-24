class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int minSum = 0;
        int n = nums.size();
        for(int i =0; i<= n/2; i++){
            if(nums[i] + nums[n-i-1] > minSum){
                minSum = nums[i] + nums[n-i-1];
            }
        }
        return minSum;
    }
};