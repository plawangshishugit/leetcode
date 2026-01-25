class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l = 0, r = 0, maxLen = 0;
        for(r =0; r<s.size(); r++){
            if(mp.find(s[r]) != mp.end()){
                l = mp[s[r]]+= 1;
            }
            mp[s[r]]= r;
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};