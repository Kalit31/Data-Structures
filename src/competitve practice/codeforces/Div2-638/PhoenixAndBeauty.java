import java.util.ArrayList;
import java.util.Scanner;

public class PhoenixAndBeauty {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t > 0) {
            int n = in.nextInt();
            int k = in.nextInt();
            ArrayList<Integer> list = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                int v = in.nextInt();
                if (!list.contains(v))
                    list.add(v);
            }
            if (list.size() > k) {
                System.out.println("-1");
            } else {
                int add = 1;
                while (list.size() < k) {
                    if (!list.contains(add)) {
                        list.add(add);
                    }
                    add++;
                }
                System.out.println(n * k);
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < k; j++) {
                        System.out.print(list.get(j) + " ");
                    }
                }
                System.out.println();
            }

            t--;
        }
        in.close();
    }
}

// int sum = 0;
// for (int i = 0; i < k; i++) {
// sum += list.get(i);
// }
// int compareSum;
// int i = 0;
// while (list.size() <= 10000 && (i + k < list.size())) {
// compareSum = sum;
// compareSum -= list.get(i);
// compareSum += list.get(i + k);
// if (compareSum != sum) {
// if (compareSum < sum)
// list.add(i + k, sum - list.get(i));
// else
// list.add(i + k, sum - list.get(i + k));
// }
// i++;
// }

// if (list.size() > 10000)
// System.out.println("-1");
// else {
// System.out.println(list.size());
// for (int j = 0; j < list.size(); j++)
// System.out.print(list.get(j) + " ");
// System.out.println();
// }