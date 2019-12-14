package linkedList;

import node.SingleNode;

public class SingleLinkedListMain {
    public static void main(String[] args) {
        SingleLinkedList singleLinkedList = new SingleLinkedList();
        singleLinkedList.createSingleLinkedList(1);
        singleLinkedList.traverseLinkedList();

        singleLinkedList.insertValue(2,1);
        singleLinkedList.traverseLinkedList();

        singleLinkedList.insertValue(3,2);
        singleLinkedList.traverseLinkedList();

        singleLinkedList.insertValue(4,2);
        singleLinkedList.traverseLinkedList();

    }
}
