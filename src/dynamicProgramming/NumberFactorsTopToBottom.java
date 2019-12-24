package dynamicProgramming;

//19818064ns
public class NumberFactorsTopToBottom {
    public static void main(String[] args) {
        int n=10;
        int[] dp = new int[n+1];
        long start = System.nanoTime();
        System.out.println("Ways to represent "+n+": "+waysToGetN(dp,n));
        long end = System.nanoTime();
        System.out.println("\n\nTime to execute this algo: " + (end-start));
    }
    public static int waysToGetN(int[] dp, int n){
        if((n==0)||(n==1)||(n==2))
            return 1;
        if(n==3)
            return 2;
        if(dp[n]==0){
            dp[n]=waysToGetN(dp,n-1)+waysToGetN(dp,n-3)+waysToGetN(dp,n-4);
        }
        return dp[n];
    }
}
