class Solution {
public: 
    bool isPalindrome(string s) 
    {
//         string temp = "";
//         int len = s.length();
//         for(int i=0;i<len;i++)
//         {
//             if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<= 'Z') || (s[i]>=0 && s[i]<=9))
//             {
//                 temp.push_back(s[i]);
//             }
//         }
        
//         int len1 = temp.length();
//         for(int i = 0;i<len1;i++){
//             if(temp[i]>='A' && temp[i]<='Z'){
//                 return (temp[i] - 'A' + 'a');
//             }
//             else{
//                 return temp[i];
//             }
//         }
        
        
//         int st = 0;
//         int end = temp.length()-1;
//         string temp1 = "";
//         while(end>=0)
//         {
//             temp1.push_back(temp[end]);
//             end--;
            
//         }
        
//         if(temp == temp1){
//             return 1;
//         }
//         else{
//             return 0;
//         }
        
        string temp = "";
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(isalnum(s[i])) {
                temp.push_back(tolower(s[i])); // Convert to lowercase
            }
        }
        
        int st = 0;
        int end = temp.length() - 1;
        string temp1 = "";
        while(end >= 0) {
            temp1.push_back(temp[end]);
            end--;
        }
        
        if(temp == temp1) {
            return true; // Return true for palindrome
        } else {
            return false; // Return false otherwise
        }
     }
};