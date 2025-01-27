class Solution {
    public boolean isHappy(int n) {
        int slow = n;
        int fast = getNext(n); // Fast starts one step ahead

        // Use Floyd's Cycle Detection Algorithm
        while (fast != 1 && slow != fast) {
            slow = getNext(slow); // Move slow one step
            fast = getNext(getNext(fast)); // Move fast two steps
        }

        // If fast reaches 1, it's a happy number
        return fast == 1;
    }

    // Helper function to calculate the sum of squares of digits
    private int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
}