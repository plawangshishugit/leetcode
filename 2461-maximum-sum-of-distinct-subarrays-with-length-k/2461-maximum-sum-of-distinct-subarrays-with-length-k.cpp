class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long sum = 0, maxSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            freq[nums[right]]++;

            // Shrink window if size exceeds k
            if (right - left + 1 > k) {
                sum -= nums[left];
                freq[nums[left]]--;

                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);

                left++;
            }

            // Valid window: size k & all elements distinct
            if (right - left + 1 == k && freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
