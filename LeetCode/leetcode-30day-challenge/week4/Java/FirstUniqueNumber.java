import java.util.HashMap;
import java.util.Map;

class Node {
    int value;
    Node prev;
    Node next;
}

class FirstUnique {

    Node head;
    Node tail;
    Map<Integer, Node> map;

    public FirstUnique(int[] nums) {
        map = new HashMap<Integer, Node>();
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;

        for (int i = 0; i < nums.length; i++) {
            add(nums[i]);
        }
    }

    public int showFirstUnique() {
        if (head.next != tail) {
            return head.next.value;
        } else {
            return -1;
        }
    }

    public void add(int value) {
        if (!map.containsKey(value)) {
            Node n = new Node();
            n.value = value;
            tail.prev.next = n;
            n.prev = tail.prev;
            tail.prev = n;
            n.next = tail;
            map.put(value, n);
        } else {
            Node n = map.get(value);
            if (n != null) {
                n.prev.next = n.next;
                n.next.prev = n.prev;
                map.put(value, null);
            }
        }
    }
}