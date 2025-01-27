class Solution {
    public boolean isHappy(int n) {
        Set<Integer> seen = new HashSet<>();
        while (n != 1 && !seen.contains(n)) {
            seen.add(n);
            int sqSum = 0;
            while (n > 0) {
                int digit = n % 10;
                sqSum += digit * digit;
                n /= 10;
            }
            n = sqSum;
        }
        return n == 1;
    }
}