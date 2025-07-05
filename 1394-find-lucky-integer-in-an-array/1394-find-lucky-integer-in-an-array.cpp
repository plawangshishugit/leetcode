class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[501] = {0};
        for(int i = 0;i< arr.size();i++){
            cnt[arr[i]] += 1;
        }
        int maxnum = -1;
        for (int i = 1; i<500;i++){
            if(i == cnt[i]){
                maxnum = i;
            }
        }
        return maxnum;
    }
};