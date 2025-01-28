class Solution {
    public int findMaxFish(int[][] grid) {
        int maxFish = 0;
        int m = grid.length;
        int n = grid[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int currentFish = dfs(grid, i, j);
                    maxFish = Math.max(maxFish, currentFish);
                }
            }
        }
        
        return maxFish;
    }
    
    private int dfs(int[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == 0) {
            return 0;
        }
        
        int fish = grid[i][j];
        grid[i][j] = 0; // Mark the cell as visited by setting it to 0
        
        fish += dfs(grid, i + 1, j);
        fish += dfs(grid, i - 1, j);
        fish += dfs(grid, i, j + 1);
        fish += dfs(grid, i, j - 1);
        
        return fish;
    }
}