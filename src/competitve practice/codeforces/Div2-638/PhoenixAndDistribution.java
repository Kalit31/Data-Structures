import java.util.Arrays;
import java.util.Scanner;

public class PhoenixAndDistribution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t > 0) {
            int n = in.nextInt();
            int k = in.nextInt();
            String s = in.next();
            char[] charArr = s.toCharArray();
            Arrays.sort(charArr);
            if (charArr[0] != charArr[k - 1]) // If first is not equal to kth char, it means the chars to the lft of the
                                              // kth char are small, so other than the kth char, use all the chars to
                                              // form Ais
                System.out.println(charArr[k - 1]);
            else if (k == n || charArr[k] == charArr[n - 1]) { // if k==n all the chars must be same. OR
                                                               // if after kth char all are same.
                for (int i = 0; i < n; i = i + k) {
                    System.out.print(charArr[i]);
                }
                System.out.println();
            } else {
                System.out.print(charArr[0]); // select 1st chars and then append the remaining chars after k, put 1 to
                                              // k in other Ais.
                for (int i = k; i < n; i++) {
                    System.out.print(charArr[i]);
                }
                System.out.println();
            }
            t--;
        }
        in.close();
    }
}