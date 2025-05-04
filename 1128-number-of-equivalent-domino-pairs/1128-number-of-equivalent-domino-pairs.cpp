class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> count;
        int res = 0;
        
        for (const auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            pair<int, int> key = {min(a, b), max(a, b)};
            res += count[key];
            count[key]++;
        }
        
        return res;
    }
};