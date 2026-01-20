class Solution {
public:
    bool canJump(vector<int>& nums) {
        // kisi bhi position pe maximum kisti dur ja sakta hai ye nikalo
        int maxReach = 0; // initialize it with 0
        for(int i = 0; i<nums.size(); i++){
            if(maxReach < i) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};