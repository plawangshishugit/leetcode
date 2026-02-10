class Solution {
public:
    int findBeauty(string &temp){
        vector<int>arr(26,0);
        int len = temp.size();
        int high=0, low = INT_MAX;
        for(int i =0; i<len; i++){
            arr[temp[i] - 'a'] ++;
        }
        for(int i = 0; i< 26 ; i++){
            if(arr[i] > 0){
                high = max(high, arr[i]);
                low = min(low, arr[i]);
            }
        }
        return high-low;
    }
    int beautySum(string s) {
        int n = s.size();
        int res = 0;
        // to have all substrings
        for(int i = 0; i<n; i++){
            string temp = "";
            for(int j = i; j<n; j++){
                temp = temp + s[j];
                int currSum = findBeauty(temp);
                res = res + currSum;
            }
        }
        return res;
    }
};