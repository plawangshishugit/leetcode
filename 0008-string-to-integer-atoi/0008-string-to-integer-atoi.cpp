class Solution {
public:
    int myAtoi(string input) {
        // Your code goes here
        // method to convert string to integer
        int i =0;
        int n = input.size();

        // step1: skip leading spaces
        while( i < n && input[i] == ' '){
            i++;
        }
        //step2: Handle the sign
        int sign = 1;
        if(i < n && input[i] == '-'){
            sign = -1;
            i++;
        }else if( i<n && input[i] == '+'){
            i++;
        }

        //step3: parse digit and build the number
        long long result = 0;
        while( i< n && isdigit(input[i])){
            result = result * 10 + (input[i] - '0');
            i++;
            //step4: handle overflow and underflow
            if(result * sign >= INT_MAX){
                return INT_MAX;
            }
            if(result * sign <= INT_MIN){
                return INT_MIN;
            }
        }

        //step 5: Return the final result with sign
        return result * sign;

    }
};
