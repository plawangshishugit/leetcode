class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int maxptr = 0;
        for(int i = 0; i<nums.size() ; i++){
            if(cnt == 0){
                maxptr = i;
            }
            if(nums[i] != nums[maxptr]){
                cnt -= 1;
            }
            else if( nums [i] == nums[maxptr]){
                cnt += 1;
            }
            
        }
        return nums[maxptr];
    }
};