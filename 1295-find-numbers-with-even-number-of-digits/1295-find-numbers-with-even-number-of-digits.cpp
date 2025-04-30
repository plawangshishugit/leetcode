class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt =0;
        for(int i =0; i<n; i++){
            int dgt =0;
            while(nums[i] != 0){
                nums[i] = nums[i]/10;
                dgt += 1;
            }
            if(dgt % 2 == 0){
                cnt += 1;
            }
        }
        return cnt;
        
    }
};