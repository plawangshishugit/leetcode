class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // In case k is greater than n
        vector<int> temp(k);
        
        // Copy the last k elements to a temporary array
        for(int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }
        
        // Shift the rest of the array to the right
        for(int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        
        // Copy the elements from the temporary array back to the beginning
        for(int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
