#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            if ((s[i] - '0') % 2 != 0) {
                string result = s.substr(0, i + 1);
                // Remove leading zeros
                int start = 0;
                while (start < result.length() && result[start] == '0') {
                    start++;
                }
                if (start == result.length()) {
                    return "";
                }
                return result.substr(start);
            }
        }
        return "";
    }
};