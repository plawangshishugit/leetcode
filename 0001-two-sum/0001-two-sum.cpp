class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int len = nums.size();
        for(int i = 0; i<len;i++){
            int more = target - nums[i];
            if(mpp.find(more) != mpp.end()){
                return{i,mpp[more]}; // mpp[more] ye pahle ka number jo iske corresponding store hua tha uska index dega map.find() -> ye index return krta hai.
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};