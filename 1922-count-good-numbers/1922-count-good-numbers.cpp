#include <cmath>

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long even_pos = (n + 1) / 2;
        long long odd_pos = n / 2;
        long long mod = 1e9 + 7;
        
        auto power = [mod](long long base, long long exp) {
            long long result = 1;
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % mod;
                }
                base = (base * base) % mod;
                exp /= 2;
            }
            return result;
        };
        
        long long even_choices = power(5, even_pos);
        long long odd_choices = power(4, odd_pos);
        
        return (even_choices * odd_choices) % mod;
    }
};