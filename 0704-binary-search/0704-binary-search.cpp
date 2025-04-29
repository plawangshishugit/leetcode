class Solution{
public:
    int search(vector<int> &nums, int target)
    {
        return bs(nums, 0 , nums.size()-1, target);
    }
private:
    int bs(vector<int> &nums, int s, int e, int target){
        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(target < nums[mid]){
                return bs(nums, s , mid -1, target);
            }else{
                return bs(nums, mid+1, e , target);
            }
        }
        return -1;
    }
};