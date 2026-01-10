class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        long long sum = 0, maxSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Remove duplicates
            while (st.count(nums[right])) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            st.insert(nums[right]);
            sum += nums[right];

            // Maintain window size k
            if (st.size() > k) {
                st.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            // Valid window
            if (st.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
