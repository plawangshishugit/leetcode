// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());

        long long waitingTime = 0;
        long long total = 0;

        for (int i = 0; i < bt.size(); i++) {
            total += waitingTime;
            waitingTime += bt[i];
        }

        return total / bt.size();  
    }
};
