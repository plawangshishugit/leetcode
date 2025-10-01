class Solution {
public:
    unordered_set<string> st;  // Stores dictionary words for O(1) lookup
    int n;                     // Length of the input string
    int t[301];                // Memoization table: -1 = not visited, 0 = false, 1 = true

    // Recursive helper function
    bool solve(int idx, string &s) {
        // Base case: if we reached the end of the string, return true
        if (idx == n) return true;

        // If already computed, return stored result
        if (t[idx] != -1) return t[idx];

        // Try every possible substring starting at idx
        for (int l = 1; l + idx <= n; l++) {
            string temp = s.substr(idx, l);  // Substring of length l starting from idx

            // If substring exists in dictionary AND rest of the string can also be segmented
            if (st.find(temp) != st.end() && solve(idx + l, s)) {
                return t[idx] = 1;  // Store and return true
            }
        }

        // If no valid split found, mark false
        return t[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();                   // Total length of the input string
        memset(t, -1, sizeof(t));         // Initialize DP table with -1 (uncomputed)

        // Insert all words of dictionary into set for fast lookup
        for (string &word : wordDict) {
            st.insert(word);
        }

        // Start recursion from index 0
        return solve(0, s);
    }
};
