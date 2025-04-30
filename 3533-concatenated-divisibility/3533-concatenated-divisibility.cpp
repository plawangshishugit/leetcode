#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int k, n;
    vector<int> nums;
    vector<bool> used;
    vector<int> pow10; // 10^len % k
    vector<int> numDigits;
    unordered_map<long long, bool> memo;
    vector<int> result;
    bool found = false;

    int getDigits(int x) {
        return x > 0 ? (int)log10(x) + 1 : 1;
    }

    long long getKey(int mask, int mod) {
        return ((long long)mask << 10) | mod;
    }

    void preprocess() {
        numDigits.resize(n);
        pow10.resize(11);
        for (int i = 0; i < n; ++i)
            numDigits[i] = getDigits(nums[i]);

        pow10[0] = 1 % k;
        for (int i = 1; i <= 10; ++i)
            pow10[i] = (pow10[i - 1] * 10) % k;
    }

    bool dfs(int mask, int mod, vector<int>& path) {
        if (found) return true;
        if (mask == (1 << n) - 1) {
            if (mod == 0) {
                result = path;
                found = true;
                return true;
            }
            return false;
        }

        long long key = getKey(mask, mod);
        if (memo.count(key)) return false;
        memo[key] = true;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) continue;

            // skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !(mask & (1 << (i - 1)))) continue;

            int len = numDigits[i];
            int newMod = (mod * pow10[len] + nums[i]) % k;

            path.push_back(nums[i]);
            if (dfs(mask | (1 << i), newMod, path)) return true;
            path.pop_back();
        }

        return false;
    }

    vector<int> concatenatedDivisibility(vector<int>& nums_, int k_) {
        nums = nums_;
        k = k_;
        n = nums.size();
        sort(nums.begin(), nums.end());
        preprocess();

        vector<int> path;
        dfs(0, 0, path);
        return result;
    }
};
