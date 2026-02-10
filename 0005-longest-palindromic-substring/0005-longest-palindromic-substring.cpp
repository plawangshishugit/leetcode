class Solution {
public:
    bool checkPln( string &temp){
        int n = temp.size();
        int i =0, j = n-1;
        while(i<=j){
            if(temp[i] != temp[j]){
                return false;
            }
            i+= 1;
            j-= 1;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int maxLen = 0;
        for(int i =0; i<n;i++){
            string temp = "";
            for(int j = i; j <n; j++){
                temp += s[j];
                if(checkPln(temp)){
                    int len = temp.size();
                    if (len > maxLen){
                        ans = temp;
                        maxLen = len;
                    }
                }
            }
        }
        return ans;
    }
};