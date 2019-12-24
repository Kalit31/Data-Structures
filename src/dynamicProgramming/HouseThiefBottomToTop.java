package dynamicProgramming;

public class HouseThiefBottomToTop {
    public static void main(String[] args) {
        int[] HouseNetWorth = {6, 7, 1, 30, 8, 2, 4};
        System.out.println(findMaxSteal(HouseNetWorth));
        HouseNetWorth = new int[] {20, 5, 1, 13, 6, 11, 40};
        System.out.println(findMaxSteal(HouseNetWorth));
    }

    public static int findMaxSteal(int[] wealth){
        int[] dp = new int[wealth.length+2];
      //  dp[wealth.length] = 0; <-- array already initialized to all '0's
        for(int i = wealth.length-1;i>=0;i--){
            dp[i] = Math.max(wealth[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
}
