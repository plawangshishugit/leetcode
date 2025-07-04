class Solution {
public:
    string largestOddNumber(string num) {
        int j = -1;
        int len = num.length();
        int i ;
        for( i = len; i>=0; i--){
            if((num[i] -'0')% 2 ==1) {
                j = i;
                break;
            }
        }
        i =0;
        while(i <= j && num[i] == '0'){
            i++;
        }

        return num.substr(i,j-i+1);
    }
};