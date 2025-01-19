class Solution {
    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        int max = 0, sum = 0;
        for (int num : nums) {
            max = Math.max(max, num);
            sum += num;
        }

        int l = max, h = sum;
        while (l < h) { // outside lop, l == h
            int mid = l + (h - l) / 2;
            int pieces = split(nums, mid);
            if (pieces <= k) { // a valid mid, but can still try to tighten it
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }

    private int split(int[] nums, int sum) {
        int pieces = 1;
        int tempSum = 0;
        for (int num : nums) {
            if (num + tempSum > sum) {
                tempSum = num;
                pieces++;
            } else {
                tempSum += num;
            }
        }

        return pieces;
    }
}
