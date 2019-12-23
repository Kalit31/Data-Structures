package greedyAlgo.coinChange;

import java.util.Arrays;

public class CoinChange {

    public static void coinChange(int[] coins, int N){
        Arrays.sort(coins);
        int index = coins.length;
        while(index-->0){
            if(coins[index]>N){
                continue;
            }
            System.out.println("Coin value: "+coins[index]+" taken count: "+(N/coins[index]));
            N = N - (N/coins[index])*coins[index];
            if(N==0)
                break;
        }
    }

}
