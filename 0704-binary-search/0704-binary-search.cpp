class Solution {
public:
    int bs(vector<int>&nums,int s, int e, int target)
    {
        if(s>e)return -1;

        int mid = s + (e-s)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        if(target > nums[ mid]){
            return bs(nums,mid+1, e, target);
        }else{
            return bs(nums,s,mid-1,target);
        }

    }   

    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        return bs(nums,s,e,target);
        
    }
};