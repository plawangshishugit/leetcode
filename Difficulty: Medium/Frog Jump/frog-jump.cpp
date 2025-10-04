class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev1 = 0, prev2 = 0; 
        
        for(int i = 1; i < n; i++) {
            int left = prev1 + abs(height[i] - height[i-1]);
            int right = INT_MAX;
            if(i > 1) right = prev2 + abs(height[i] - height[i-2]);
            
            int curr = min(left, right);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};
