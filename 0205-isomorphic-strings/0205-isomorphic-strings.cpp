class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char> stot;
       unordered_map<char,char>ttos;
       for(int i =0; i<s.size(); i++){
        char a = s[i];
        char b = t[i];
        //check s-> t mapping
        if(stot.count(a) && stot[a] != b){
            return false;
        }
        // check t -> s mapping
        if(ttos.count(b) && ttos[b] != a){
            return false;
        }
        stot[a] = b;
        ttos[b] = a;
       }
       return true;
    }
};