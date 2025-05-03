class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int result = INT_MAX;
        

        for (int target : {tops[0], bottoms[0]}) {
            int topRotations = 0;
            int bottomRotations = 0;
            bool possible = true;
            
            for (int i = 0; i < n; ++i) {
                if (tops[i] != target && bottoms[i] != target) {
                    possible = false;
                    break;
                }
                if (tops[i] != target) {
                    topRotations++;
                }
                if (bottoms[i] != target) {
                    bottomRotations++;
                }
            }
            
            if (possible) {
                result = min(result, min(topRotations, bottomRotations));
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};