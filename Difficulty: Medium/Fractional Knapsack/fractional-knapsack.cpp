class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        // store (value, weight) pairs
        vector<pair<int,int>> items;
        for (int i = 0; i < n; i++) {
            items.push_back({val[i], wt[i]});
        }
        
        // sort by value-to-weight ratio in descending order
        sort(items.begin(), items.end(), [](pair<int,int>& a, pair<int,int>& b) {
            double r1 = (double)a.first / a.second;
            double r2 = (double)b.first / b.second;
            return r1 > r2;
        });
        
        double totalValue = 0.0;
        int curWeight = 0;
        
        for (int i = 0; i < n; i++) {
            if (curWeight + items[i].second <= capacity) {
                // take full item
                curWeight += items[i].second;
                totalValue += items[i].first;
            } else {
                // take fractional part
                int remain = capacity - curWeight;
                totalValue += (double)items[i].first * ((double)remain / items[i].second);
                break; // knapsack full
            }
        }
        
        // round to 6 decimal places
        return round(totalValue * 1e6) / 1e6;
    }
};
