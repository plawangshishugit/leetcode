class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long left = 0;
        long long current_sum = 0;
        long long count = 0;
        
        for (long long right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];
            
            while (current_sum * (right - left + 1) >= k) {
                current_sum -= nums[left];
                left++;
            }
            
            count += right - left + 1;
        }
        
        return count;
    }
};