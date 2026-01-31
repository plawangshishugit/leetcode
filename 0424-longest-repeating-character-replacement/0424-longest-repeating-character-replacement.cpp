class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);   // Frequency of characters
        int left = 0;
        int maxFreq = 0;           // Max frequency in current window
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If replacements needed > k, shrink window
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};