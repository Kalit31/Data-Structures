package divideAndConquer;

//20723155 ns
public class NumberFactors {
    public static void main(String[] args) {
        int n=100;
        long start = System.nanoTime();
        System.out.println("Ways to represent "+n+": "+waysToGetN(n));
        long end = System.nanoTime();
        System.out.println("\n\nTime to execute this algo: " + (end-start));
    }

    public static int waysToGetN(int n){
        if((n==0)||(n==1)||(n==2))
            return 1;
        else if(n==3)
            return 2;
        else
            return waysToGetN(n-1)+waysToGetN(n-3)+waysToGetN(n-4);
    }
}
