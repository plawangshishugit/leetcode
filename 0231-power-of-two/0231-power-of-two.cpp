class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<32> binary(n);
        int cnt = 0;
        if (n <= 0) return false;
        for(int i= 0; i<32; i++)
        {
            if( binary[i] == 1){
                cnt+= 1;
            }
           
            
        }
        if((cnt == 1) ){
            return true;
        }
        else{
            return false;
        }
    }
};