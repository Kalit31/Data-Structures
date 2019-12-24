package dynamicProgramming;

public class ZeroOneKnapSackTopToBottom {
    public static void main(String[] args) {
        int[] profits = { 31, 26, 72, 17 };
        int[] weights = { 3, 1, 5, 2 };
        int capacity = 7;
        Integer[][] dp = new Integer[profits.length][capacity + 1];
        int maxProfit = knapsack(dp,profits, weights, capacity,0);
        System.out.println(maxProfit);
    }
    public static int knapsack(Integer[][] dp,int[] profits,int[] weights,int capacity,int currentIndex){
      if (capacity <= 0 || currentIndex < 0 || currentIndex >= profits.length)
            return 0;
        if (dp[currentIndex][capacity] != null) // if we have already solved this problem, then return the result from memory
            return dp[currentIndex][capacity];

        int profit1 = 0;

        if(weights[currentIndex]<=capacity){
            profit1 = profits[currentIndex] + knapsack(dp,profits, weights, capacity - weights[currentIndex], currentIndex + 1);
        }
        int profit2 =  knapsack(dp,profits, weights, capacity, currentIndex + 1);
        dp[currentIndex][capacity] = Math.max(profit1,profit2);
        return dp[currentIndex][capacity];
    }
}
