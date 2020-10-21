package dynamicProgramming;

public class MinCostToReachLastCellTB {
    public static void main(String[] args) {
        int[][] array =
                {
                        { 4, 7, 8, 6, 4 },
                        { 6, 7, 3, 9, 2 },
                        { 3, 8, 1, 2, 4 },
                        { 7, 1, 7, 3, 7 },
                        { 2, 9, 8, 9, 3 }
                };
        Integer[][] dp = new Integer[array.length+1][array.length+1];
        System.out.print("The minimum cost is " + findMinCost(dp,array, array.length-1, array[0].length-1));

    }
    public static int findMinCost(Integer[][] dp,int[][] cost, int row, int col) {
        if (row == -1 || col == -1) {
            return Integer.MAX_VALUE;
        }
        if (row == 0 && col == 0) {
            return cost[0][0];
        }
        if(dp[row][col]==null) {
            int minCost1 = findMinCost(dp, cost, row - 1, col);//Case#1 Get min cost if we go 'up' from current cell
            int minCost2 = findMinCost(dp, cost, row, col - 1);//Case#2 Get min cost if we go 'left' from current cell
            int minCost = Integer.min(minCost1, minCost2);
            int currentCellsCost = cost[row][col];
            dp[row][col] = minCost + currentCellsCost;
        }
        return dp[row][col];
    }
}
