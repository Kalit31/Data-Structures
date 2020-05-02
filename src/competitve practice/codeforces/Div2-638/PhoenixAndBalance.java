import java.util.Scanner;

public class PhoenixAndBalance {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t > 0) {
            int n = in.nextInt();
            long a = (long) Math.pow(2, n);
            long b = (long) Math.pow(2, (n + 1) / 2);
            b = b - 2;
            long result = a + b;
            long c = a - 2 - b;
            System.out.println(result - c);
            t--;
        }
        in.close();
    }
}