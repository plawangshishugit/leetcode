class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0) {
            return 0;
        }

        int maxArea = 0;
        for (int i = 0; i < heights.length; i++) {
            int currentHeight = heights[i];
            int left = i;
            int right = i;

            // Expand to the left
            while (left > 0 && heights[left - 1] >= currentHeight) {
                left--;
            }

            // Expand to the right
            while (right < heights.length - 1 && heights[right + 1] >= currentHeight) {
                right++;
            }

            // Calculate the width
            int width = right - left + 1;
            int area = currentHeight * width;
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }
}