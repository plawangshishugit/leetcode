class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& ds, vector<vector<int>>& ans) {
        // Base case
        if (ds.size() == k && n == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) break; // pruning: no need to proceed further

            ds.push_back(i);
            backtrack(i + 1, k, n - i, ds, ans); // move to next number
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(1, k, n, ds, ans);
        return ans;
    }
};
