class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        int curr = -1;
        int size = 0;
        int prev = -101;
        int count =0;
        for(int i = 0; i<l; i++ ){
            if(nums[i] >prev){
                count += 1;
                nums[curr+1] = nums[i];
                curr +=1;
            }
            prev = nums[i];
        }
        return count;
    }
};
