class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0)
                return false;
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // Preprocess divisor → indices where nums[j] % divisor == 0
        unordered_map<int, vector<int>> divisor_to_indices;
        for (int j = 0; j < n; ++j) {
            for (int d = 1; d * d <= nums[j]; ++d) {
                if (nums[j] % d == 0) {
                    divisor_to_indices[d].push_back(j);
                    if (d != nums[j] / d)
                        divisor_to_indices[nums[j] / d].push_back(j);
                }
            }
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;

        unordered_set<int> used_primes;
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front(); q.pop();

                if (i == n - 1) return steps;

                // Step to i+1
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // Step to i-1
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // Prime teleportation using precomputed divisor indices
                int val = nums[i];
                if (isPrime(val) && !used_primes.count(val)) {
                    for (int j : divisor_to_indices[val]) {
                        if (!visited[j]) {
                            visited[j] = true;
                            q.push(j);
                        }
                    }
                    used_primes.insert(val);
                }
            }
            steps++;
        }

        return -1;
    }
};
