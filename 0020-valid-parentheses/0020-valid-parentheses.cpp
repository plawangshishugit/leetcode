class Solution {
private: 

    bool isMatched(char open, char close) {
    
        // Match
        if((open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}')
        )
        return true;
        
        // Mismatch
        return false;
    }
public:
    bool isValid(string str) {
       stack<char>st;
       for(int i =0; i<str.length();i++)
       {
        if(str[i] == '(' || str[i] == '[' || 
               str[i] == '{') {
                // Push on top of stack
                st.push(str[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                char ch = st.top();
                st.pop();

                if(!isMatched(ch, str[i])){
                    return false;
                }
            }
       }
       return st.empty();
    }
};