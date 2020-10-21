package dynamicProgramming;

public class HouseThiefTopToBottom {
    public static void main(String[] args) {
        int[] HouseNetWorth = {6, 7, 1, 30, 8, 2, 4};
        int[] dp = new int[HouseNetWorth.length];
        System.out.println(maxMoneyRecursive(dp,HouseNetWorth,0));
        HouseNetWorth = new int[] {20, 5, 1, 13, 6, 11, 40};
        dp = new int[HouseNetWorth.length];
        System.out.println(maxMoneyRecursive(dp,HouseNetWorth,0));
    }
    public static int maxMoneyRecursive(int[] dp, int[] houseNetWorth,int currentIndex){
        if(currentIndex>=houseNetWorth.length)
            return 0;
        if(dp[currentIndex]==0) {
            int stealCurrentHouse = houseNetWorth[currentIndex] + maxMoneyRecursive(dp,houseNetWorth, currentIndex + 2);
            int skipCurrentHouse = maxMoneyRecursive(dp,houseNetWorth, currentIndex + 1);
            dp[currentIndex]=Math.max(stealCurrentHouse,skipCurrentHouse);
        }
        return dp[currentIndex];
    }
}
