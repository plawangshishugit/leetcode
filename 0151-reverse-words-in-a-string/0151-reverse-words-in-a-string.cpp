#include <vector>
#include <algorithm>

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string current;
        
        for (char c : s) {
            if (c != ' ') {
                current += c;
            } else {
                if (!current.empty()) {
                    words.push_back(current);
                    current.clear();
                }
            }
        }
        
        // Add the last word if there's any
        if (!current.empty()) {
            words.push_back(current);
        }
        
        reverse(words.begin(), words.end());
        
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i != 0) {
                result += " ";
            }
            result += words[i];
        }
        
        return result;
    }
};