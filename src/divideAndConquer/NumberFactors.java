package divideAndConquer;

public class NumberFactors {
    public static void main(String[] args) {
        int n=10;
        System.out.println("Ways to represent "+n+": "+waysToGetN(n));
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
