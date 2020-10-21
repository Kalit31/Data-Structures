
class LRUCache {
    class Node {
        int key;
        int value;
        Node next;
        Node prev;
    }

    Node head = new Node();
    Node tail = new Node();
    Map<Integer, Node> map;
    int cap;

    public LRUCache(int capacity) {
        this.map = new HashMap<Integer, Node>(capacity);
        this.cap = capacity;
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        int result = -1;
        Node node = map.get(key);
        if (node != null) {
            removeNode(node);
            addNode(node);
            result = node.value;
        }
        return result;
    }

    public void put(int key, int value) {
        Node node = map.get(key);

        if (node != null) {
            removeNode(node);
            node.value = value;
            addNode(node);
        } else {
            if (map.size() == cap) {
                Node toRemove = tail.prev;
                map.remove(toRemove.key);
                removeNode(toRemove);
            }

            node = new Node();
            node.key = key;
            node.value = value;
            map.put(key, node);
            addNode(node);
        }
    }

    public void addNode(Node node) {
        node.next = head.next;
        head.next.prev = node;
        head.next = node;
        node.prev = head;
    }

    public void removeNode(Node node) {
        Node next = node.next;
        Node prev = node.prev;
        next.prev = prev;
        prev.next = next;
    }

}

/**
 * Your LRUCache object will be instantiated and called as such: LRUCache obj =
 * new LRUCache(capacity); int param_1 = obj.get(key); obj.put(key,value);
 */

class LRUCache2 {
    Map<Integer, Integer> map;
    List<Integer> list;
    int capacity;

    public LRUCache2(int capacity) {
        this.map = new HashMap<Integer, Integer>();
        this.list = new ArrayList<Integer>();
        this.capacity = capacity;
    }

    public int get(int key) {
        int result = -1;
        if (map.containsKey(key) && list.contains(key)) {
            result = map.get(key);
            list.remove(list.indexOf(key));
            list.add(key);
        }
        return result;
    }

    public void put(int key, int value) {
        if (list.contains(key))
            list.remove(list.indexOf(key));

        if (list.size() < capacity) {
            list.add(key);
        } else {
            list.remove(0);
            list.add(key);
        }
        map.put(key, value);
    }
}