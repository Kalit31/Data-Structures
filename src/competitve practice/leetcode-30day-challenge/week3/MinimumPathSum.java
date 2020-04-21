class Solution {

    public int calculateMin(int[][] dp, int[][] grid, int row, int col) {
        if (row == -1 || col == -1) {
            return Integer.MAX_VALUE;
        }
        if (row == 0 && col == 0) {
            return grid[0][0];
        }
        if (dp[row][col] == 0) {
            int min1 = calculateMin(dp, grid, row - 1, col);
            int min2 = calculateMin(dp, grid, row, col - 1);
            int min = Math.min(min1, min2);
            dp[row][col] = grid[row][col] + min;
        }
        return dp[row][col];
    }

    public int minPathSum(int[][] grid) {
        int[][] dp = new int[grid.length + 1][grid[0].length + 1];

        return calculateMin(dp, grid, grid.length - 1, grid[0].length - 1);

    }
}