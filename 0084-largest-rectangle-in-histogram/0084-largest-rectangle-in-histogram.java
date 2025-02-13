import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0) {
            return 0;
        }

        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        int index = 0;

        while (index < heights.length) {
            // Push to stack if the current bar is taller than the bar at the top of the stack
            if (stack.isEmpty() || heights[index] >= heights[stack.peek()]) {
                stack.push(index);
                index++;
            } else {
                // Calculate the area of the rectangle with the top of the stack as the smallest bar
                int top = stack.pop();
                int width = stack.isEmpty() ? index : index - stack.peek() - 1;
                int area = heights[top] * width;
                maxArea = Math.max(maxArea, area);
            }
        }

        // Process the remaining bars in the stack
        while (!stack.isEmpty()) {
            int top = stack.pop();
            int width = stack.isEmpty() ? index : heights.length - stack.peek() - 1;
            int area = heights[top] * width;
            maxArea = Math.max(maxArea, area);
        }

        return maxArea;
    }
}