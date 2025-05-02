class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        row.push_back(1);
        for (int k = 1; k <= rowIndex; ++k) {
            long next_val = (long)row.back() * (rowIndex - k + 1) / k;
            row.push_back(next_val);
        }
        return row;
    }
};