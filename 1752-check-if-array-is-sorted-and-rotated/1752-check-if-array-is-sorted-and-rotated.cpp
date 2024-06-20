class Solution {
public:
    bool check(vector<int>& nums) {
        int countDecreases = 0;
        // int n = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[(i + 1) % nums.size()]) {
                countDecreases++;
            }
        }
        
        return countDecreases <= 1;
    }
};
