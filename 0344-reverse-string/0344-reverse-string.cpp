class Solution {
public:
    void reverseString(vector<char>& s) {
        // int len = 0;
        // for(int i =0; s[i] != '\0'; i++){
        //     len ++;
        // }
        int len= size(s);
        int st =0;
        int end = len -1;
        while(st<end){
            swap(s[st++],s[end--]);
        }
    }
};