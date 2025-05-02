class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> R_force(n, INT_MAX);
        vector<int> L_force(n, INT_MAX);
     
        int current_force = 0;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                current_force = 1;
                R_force[i] = 0;
            } else if (dominoes[i] == 'L') {
                current_force = 0;
            } else {
                if (current_force > 0) {
                    R_force[i] = current_force;
                    current_force++;
                }
            }
        }
        
     
        current_force = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                current_force = 1;
                L_force[i] = 0;
            } else if (dominoes[i] == 'R') {
                current_force = 0;
            } else {
                if (current_force > 0) {
                    L_force[i] = current_force;
                    current_force++;
                }
            }
        }
        
   
        string result;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] != '.') {
                result.push_back(dominoes[i]);
                continue;
            }
            if (R_force[i] < L_force[i]) {
                result.push_back('R');
            } else if (L_force[i] < R_force[i]) {
                result.push_back('L');
            } else {
                result.push_back('.');
            }
        }
        return result;
    }
};