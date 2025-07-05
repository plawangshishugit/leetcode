class Solution {
public:
    int divide(int dividend, int divisor) {
        
        bool sign = (dividend < 0) == (divisor < 0);

        long n = labs(dividend);
        long d = labs(divisor);

        long quotient = 0;
        while (n >= d) {
            long temp = d, multiple = 1;
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        quotient = sign ? quotient : -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
