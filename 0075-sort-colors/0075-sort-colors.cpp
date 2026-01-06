class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int low = 0;
        int mid = 0;
        int high = len-1;
        while(high>=mid){
            if(nums[mid]==1){
                mid +=1;
            }
            else{
                if(nums[mid] ==2){
                    swap(nums[mid], nums[high]);
                    if(nums[high]==2) high -=1;
                }
                else{
                    if(nums[mid]==0){
                        swap(nums[mid], nums[low]);
                        if(nums[low]==0){ low += 1;}
                        mid +=1;
                        
                    }
                }
            }
        }
    }
};