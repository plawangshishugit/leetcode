class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int low = 0; int high = 0; unordered_map<char,int>mp;
        int n = s.size();
        int maxLen = -1;
        while(high < n){
            mp[s[high]]++;
            while(mp.size() > k){
                mp[s[low]]--;
                if(mp[s[low]] == 0){
                    mp.erase(s[low]);
                }
                low ++;
            }
            if(mp.size() == k){
                maxLen = max(maxLen, high -low + 1);
            }
            high ++;
        }
        return maxLen;
    }
};