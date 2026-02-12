class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long intPow(long long x, long long n) {
        long long result = 1;
        x %= MOD;  // Handle large base
        while (n > 0) {
            if (n % 2 == 1)
                result = (result * x) % MOD;
            x = (x * x) % MOD;
            n /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenWays = intPow(5, evenPositions);
        long long oddWays = intPow(4, oddPositions);

        return (evenWays * oddWays) % MOD;
    }
};
