import java.util.*;

public class RoadToZero {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();

        for (int i = 1; i <= t; i++) {
            long x = in.nextInt();
            long y = in.nextInt();
            long a = in.nextInt();
            long b = in.nextInt();

            if (x == 0 && y == 0) {
                System.out.println(0);
                continue;
            }

            long min = Math.min(x, y);
            long max = Math.max(x, y);

            long o1 = min * b + (max - min) * a;
            long o2 = (max + min) * a;
            System.out.println(Math.min(o1, o2));
        }
        in.close();
    }

}