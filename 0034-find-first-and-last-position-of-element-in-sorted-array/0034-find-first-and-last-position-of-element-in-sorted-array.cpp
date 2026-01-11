class Solution {
public:
    // Find the first position of target
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                right = mid - 1;  // keep searching on the left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    // Find the last position of target
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                left = mid + 1;  // keep searching on the right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirst(nums, target);
        int end = findLast(nums, target);
        return {start, end};
    }
};
