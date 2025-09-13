class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            bool destroyed = false;

            // collision handling
            while (!st.empty() && asteroids[i] < 0 && st.top() > 0) {
                int sum = asteroids[i] + st.top();
                if (sum < 0) {  
                    st.pop();          // right asteroid destroyed
                    continue;          // check again (current may hit more)
                } 
                else if (sum == 0) {   
                    st.pop();          // both destroyed
                    destroyed = true;
                    break;
                } 
                else {                 
                    destroyed = true;  // current destroyed
                    break;
                }
            }

            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }

        // Convert stack → vector
        int s = st.size();
        vector<int> result(s);
        for (int i = s - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
