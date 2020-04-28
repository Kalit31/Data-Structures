import java.util.Scanner;

public class Candies {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int k;
        for (int i = 1; i <= t; i++) {
            long n = in.nextLong();
            k = 2;
            while (true) {
                long div = (long) Math.pow(2, k) - 1;
                if (n % div == 0) {
                    System.out.println(n / div);
                    break;
                }
                k++;
            }
        }

        in.close();
    }
}