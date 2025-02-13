import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0) {
            return 0;
        }

        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        int n = heights.length;

        for (int i = 0; i <= n; i++) {
            // If we reach the end, use a height of 0 to force all remaining bars to be processed
            int h = (i == n) ? 0 : heights[i];

            // Pop the stack and calculate area when the current height is smaller than the stack's top
            while (!stack.isEmpty() && h < heights[stack.peek()]) {
                int height = heights[stack.pop()];
                int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxArea = Math.max(maxArea, height * width);
            }

            // Push the current index to the stack
            stack.push(i);
        }

        return maxArea;
    }
}