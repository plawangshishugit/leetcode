class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int ng = g.size();
        int ns = s.size();

        int lg = 0; // child index
        int ls = 0; // cookie index

        while (lg < ng && ls < ns) {
            if (g[lg] <= s[ls]) {
                // Assign this cookie to the child
                lg++;
            }
            // Move to next cookie either way
            ls++;
        }
        return lg; // number of satisfied children
    }
};
