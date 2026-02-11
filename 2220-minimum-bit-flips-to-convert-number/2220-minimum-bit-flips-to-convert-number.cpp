class Solution {
public:
    int minBitFlips(int start, int goal) {
        string s_bin = "";
        string g_bin = "";
        while(start > 0) {
            s_bin = char((start & 1) + '0')+s_bin;
            start = start >> 1;
        }
        while(goal > 0) {
            g_bin = char((goal & 1) + '0')+g_bin;
            goal = goal >> 1;
        }
        int slen = s_bin.size();
        int glen = g_bin.size();

        if(slen < glen){
            s_bin = string(glen - slen, '0') + s_bin;
        }
        else if (glen < slen){
            g_bin = string(slen - glen, '0') + g_bin;
        }

        int cnt = 0;
        for(int i = 0; i<s_bin.size(); i++){

            if(s_bin[i] != g_bin[i]){
                cnt += 1;
            }
            
        }
        return cnt;

    }
};