package divideAndConquer;

public class Fibonacci {
    public static void main(String[] args) {
        int n=10;
        for(int i=1;i<n;i++)
            System.out.print(calculateFibonacciSeries(i)+" ");
    }
    public static int calculateFibonacciSeries(int n){
        if(n==0)
            return Integer.MIN_VALUE;
        else if(n==1)
            return 0;
        else if(n==2)
            return 1;
        else
            return calculateFibonacciSeries(n-1)+calculateFibonacciSeries(n-2);
    }
}
