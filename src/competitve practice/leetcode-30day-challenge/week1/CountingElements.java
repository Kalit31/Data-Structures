import java.util.*;

public class CountingElements {
    public int countElements(int[] arr) {
        int count = 0;
        List<Integer> ls = new ArrayList<Integer>();
        for (int n : arr) {
            ls.add(n);
        }
        for (int n : ls) {
            if (!ls.contains(n + 1))
                continue;
            count++;
        }
        return count;
    }
}