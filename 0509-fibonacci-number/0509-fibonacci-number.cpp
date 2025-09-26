class Solution {
public:
    int fib(int n) {
        static vector<int> dp(31, -1);  // LeetCode constraint: n ≤ 30
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = fib(n-1) + fib(n-2);
    }
};
