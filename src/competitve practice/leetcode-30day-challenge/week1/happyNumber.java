import java.util.*;

class HappyNumber {
    public static boolean isHappy(int n) {
        int result;
        int num = n;
        Set<Integer> set = new HashSet<Integer>();
        while (num != 1) {
            if (!set.contains(num))
                set.add(num);
            else
                return false;
            result = 0;
            while (num > 0) {
                int remainder = num % 10;
                result = result + remainder * remainder;
                num = num / 10;
            }
            num = result;
        }
        return true;
    }

    public static void main(String args[]) {
        System.out.println(isHappy(19));
    }

}