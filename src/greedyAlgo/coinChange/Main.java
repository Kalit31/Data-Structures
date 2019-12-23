package greedyAlgo.coinChange;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int [] coins = {1, 2, 5, 10, 50, 100, 500,2000};
        int amount = 2758;
        System.out.println("Coins available: "+ Arrays.toString(coins));
        System.out.println("Target amount: "+ amount);
        CoinChange.coinChange(coins,amount);
    }
}
