import java.util.*;

class Solution1 {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>();

        for (int s : stones) {
            maxHeap.add(-s);
        }

        while (maxHeap.size() > 1) {
            int s1 = -maxHeap.remove();
            int s2 = -maxHeap.remove();
            if (s1 != s2) {
                maxHeap.add(-(s1 - s2));
            }
        }

        return maxHeap.isEmpty() ? 0 : -maxHeap.remove();
    }
}

class Solution2 {
    public int lastStoneWeight(int[] stones) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int s : stones) {
            list.add(s);
        }

        while (list.size() > 1) {
            Collections.sort(list);

            int a = list.get(list.size() - 1);
            list.remove(list.size() - 1);
            int b = list.get(list.size() - 1);
            list.remove(list.size() - 1);

            int c = a - b;

            if (c != 0)
                list.add(c);
        }
        if (list.size() != 0)
            return list.get(0);
        else
            return 0;

    }
}