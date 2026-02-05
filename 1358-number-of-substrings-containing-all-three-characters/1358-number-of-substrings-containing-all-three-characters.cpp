class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> arr(3,-1);
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i<n; i++){
            arr[s[i] - 'a'] = i;
            if(arr[0] != -1 && arr[1] != -1 && arr[2] != -1){
                cnt += (1+ min({arr[0], arr[1], arr[2]}));
            }
        }
        return cnt;
    }
};