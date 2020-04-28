import java.util.Scanner;

public class BalancedArray {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = in.nextInt();
            if ((n / 2) % 2 != 0) {
                System.out.println("NO");
                continue;
            }
            System.out.println("YES");
            int sum = 0;
            for (int j = 1; j <= n / 2; j++) {
                sum = sum + j * 2;
                System.out.print(j * 2 + " ");
            }
            for (int j = 1; j < n / 2; j++) {
                sum = sum - (2 * j - 1);
                System.out.print((2 * j - 1) + " ");
            }
            System.out.print(sum + "\n");
        }

        in.close();
    }
}