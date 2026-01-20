class Solution {
public:
    bool checkValidString(string s) {
        int low =0, high =0;
// the idea behind taking low and high that minimun number of (  is low and maximun number of ( is high so at last min of ( should be 0 and on traversing the whole string max of ( i.e. high should not less than zero. because next to ( should be something like ) or * which can be treated as ) in this case. so we make it () and can say that is a valid string.
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '('){
                low += 1;
                high += 1;
            }
            else if (s[i] == ')'){
                low -= 1;
                high -= 1;
            }
            else{ // * ko -1, 0 , +1 treat kr sakte hain to low to high ka range nikalne ke liye low-- to high++ kr rhe 
                low -= 1;
                high += 1;
            }
            //know check if low is less than 0 than make it 0 because low can never be less than 0 we are taking range and making a range we have option to -1, 0, 1 so in case it is becoming less than 0 so we wont take -1 and make it at least 0
            if(low < 0){
                low =0;
            }
            if(high < 0) return false;// because high can never be less than 0 ; socho na ki tumne sare fande apna liye pr last mein ab tk ( bach hi gya so return false.
        }
        return (low == 0);
    }
};