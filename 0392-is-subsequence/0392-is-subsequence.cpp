class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        return solve(s, t, i, j) == s.length();
    }

private:
    int solve(string &s, string &t, int i, int j) {
        if (i == s.length()) return i;  // All characters matched
        if (j == t.length()) return i;  // Reached the end of 't' but not 's'

        if (s[i] == t[j]) {
            return solve(s, t, i + 1, j + 1); // Move both pointers forward
        } else {
            return solve(s, t, i, j + 1); // Move 't' pointer only
        }
    }
};
