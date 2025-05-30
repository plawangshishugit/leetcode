class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        int partLen = part.length();

        for (char c : s) {
            result.push_back(c);
            if (result.size() >= partLen &&
                result.substr(result.size() - partLen) == part) {
                result.erase(result.end() - partLen, result.end());
            }
        }

        return result;
    }
};
