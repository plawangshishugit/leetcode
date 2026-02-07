class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char maps [128] = {0};
        char mapt[128] = {0};
        int n = s.size();
        for(int i =0; i<n; i++){
            if(maps[s[i]] != mapt[t[i]]){
                return false;
            }
            maps[s[i]] = i+ 1;
            mapt[t[i]] = i +1;

        }
        return true;
    }
};