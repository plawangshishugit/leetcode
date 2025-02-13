import java.util.Stack;

class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxArea = 0;
        int index = 0;
        
        while (index < heights.length) {
            if (stack.isEmpty() || heights[index] >= heights[stack.peek()]) {
                stack.push(index);
                index++;
            } else {
                int topOfStack = stack.pop();
                int width = stack.isEmpty() ? index : index - stack.peek() - 1;
                int area = heights[topOfStack] * width;
                maxArea = Math.max(maxArea, area);
            }
        }
        
        while (!stack.isEmpty()) {
            int topOfStack = stack.pop();
            int width = stack.isEmpty() ? index : heights.length - stack.peek() - 1;
            int area = heights[topOfStack] * width;
            maxArea = Math.max(maxArea, area);
        }
        
        return maxArea;
    }
}