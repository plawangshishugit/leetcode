class Solution {
    public int search(int[] nums, int target) {
        int pivot = findPivot(nums, 0, nums.length - 1);

        // If no pivot is found, array is not rotated, perform binary search
        if (pivot == -1) {
            return binarySearch(nums, 0, nums.length - 1, target);
        }

        // If target is the pivot element
        if (nums[pivot] == target) {
            return pivot;
        }

        // Search in the left sorted portion
        if (target >= nums[0]) {
            return binarySearch(nums, 0, pivot - 1, target);
        }

        // Search in the right sorted portion
        return binarySearch(nums, pivot + 1, nums.length - 1, target);
    }

    static int findPivot(int[] nums, int s, int e) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Check if mid is the pivot
            if (mid < e && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid > s && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }

            // Adjust search range based on sorted property
            if (nums[s] >= nums[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return -1; // No pivot found, array is not rotated
    }

    static int binarySearch(int[] nums, int s, int e, int target) {
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1; // Element not found
    }
}
