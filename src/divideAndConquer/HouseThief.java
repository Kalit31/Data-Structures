package divideAndConquer;

public class HouseThief {
    public static void main(String[] args) {
        int[] HouseNetWorth = {6, 7, 1, 30, 8, 2, 4};
        System.out.println(maxMoneyRecursive(HouseNetWorth,0));
        HouseNetWorth = new int[] {20, 5, 1, 13, 6, 11, 40};
        System.out.println(maxMoneyRecursive(HouseNetWorth,0));
    }

    public static int maxMoneyRecursive(int[] houseNetWorth,int currentIndex){
        if(currentIndex>=houseNetWorth.length)
            return 0;
        int stealCurrentHouse = houseNetWorth[currentIndex]+maxMoneyRecursive(houseNetWorth,currentIndex+2);
        int skipCurrentHouse = maxMoneyRecursive(houseNetWorth,currentIndex+1);
        return Math.max(stealCurrentHouse,skipCurrentHouse);
    }
}
