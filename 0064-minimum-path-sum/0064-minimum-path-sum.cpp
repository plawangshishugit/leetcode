class Solution {
public:
    int f(int m, int n,vector<vector<int>>&grid, vector<vector<int>>&dp ){
        //base case
        if(m==0 && n==0){
            return grid[0][0];
        }
        //out of bonds
        if(m<0 ||n<0)return INT_MAX;

        if(dp[m][n] != -1)return dp[m][n];
        
        int right = f(m,n-1,grid,dp);
        int down = f(m-1, n, grid, dp);
        return dp[m][n] =  grid[m][n] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};