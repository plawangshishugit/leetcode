class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int flag = 0;
        int n = size(nums);
        for(int i =0 ;i<n ;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            {
                flag ++;
            }
        }
       
            return flag <=1;
        
        
    }
};