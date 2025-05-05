class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        vector<long long> dp_full(n + 1, 0);
        vector<long long> dp_upper(n + 1, 0);
        vector<long long> dp_lower(n + 1, 0);
        
        dp_full[0] = 1;
        dp_full[1] = 1;
        dp_full[2] = 2;
        dp_upper[1] = 0;
        dp_upper[2] = 1;
        dp_lower[1] = 0;
        dp_lower[2] = 1;
        
        for (int i = 3; i <= n; ++i) {
            dp_full[i] = (dp_full[i-1] + dp_full[i-2] + dp_upper[i-1] + dp_lower[i-1]) % MOD;
            dp_upper[i] = (dp_full[i-2] + dp_lower[i-1]) % MOD;
            dp_lower[i] = (dp_full[i-2] + dp_upper[i-1]) % MOD;
        }
        
        return dp_full[n];
    }
};