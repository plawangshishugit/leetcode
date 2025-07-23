class Solution {
public:

    pair<int, string> removePair(string s, char first, char second, int score) {
        stack<char> st;
        int total = 0;

        for (char ch : s) {
            if (!st.empty() && st.top() == first && ch == second) {
                st.pop(); 
                total += score;
            } else {
                st.push(ch);
            }
        }

       
        string rem;
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }
        reverse(rem.begin(), rem.end());
        return {total, rem};
    }

    int maximumGain(string s, int x, int y) {
        int total = 0;

        if (x > y) {
            
            auto [score1, rem1] = removePair(s, 'a', 'b', x);
            auto [score2, rem2] = removePair(rem1, 'b', 'a', y);
            total = score1 + score2;
        } else {
           
            auto [score1, rem1] = removePair(s, 'b', 'a', y);
            auto [score2, rem2] = removePair(rem1, 'a', 'b', x);
            total = score1 + score2;
        }

        return total;
    }
};
