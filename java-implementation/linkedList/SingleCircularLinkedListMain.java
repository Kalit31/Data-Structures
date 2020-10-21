package linkedList;

public class SingleCircularLinkedListMain {
    public static void main(String[] args) {
        SingleCircularLinkedList list = new SingleCircularLinkedList();
        list. createSingleCircularLinkedList(5);
        list.insertValue(10, 1);
        list.insertValue(20, 2);
        list.insertValue(30, 3);
        list.insertValue(40, 4);

        System.out.println("Linked List now: ");
        list.traverseLinkedList();

        list.insertValue(35, 4);
        list.traverseLinkedList();

        list.insertValue(1, 0);
        list.traverseLinkedList();

        list.insertValue(100, 10);
        list.traverseLinkedList();


        list.printHeadUsingTail();

        System.out.println("Searching the node having value 40: ");
        list.searchNode(40);

        System.out.println("\n\nSearching the node having value 200: ");
        list.searchNode(200);


        System.out.println("\n\nDeleting the node having location = 2: ");
        System.out.println("Before deletion...");
        list.traverseLinkedList();
        list.deleteNode(2);
        System.out.println("After deletion...");
        list.traverseLinkedList();


        System.out.println("\n\nDeleting the node having location = 0: ");
        System.out.println("Before deletion...");
        list.traverseLinkedList();
        list.deleteNode(0);
        System.out.println("After deletion...");
        list.traverseLinkedList();


        System.out.println("\n\nDeleting the node having location = 15: ");
        System.out.println("Before deletion...");
        list.traverseLinkedList();
        list.deleteNode(15);
        System.out.println("After deletion...");
        list.traverseLinkedList();


        System.out.println("\n\nDeleting the node having location = 15: ");
        System.out.println("Before deletion...");
        list.traverseLinkedList();
        list.deleteNode(15);
        System.out.println("After deletion...");
        list.traverseLinkedList();


        list.deleteLinkedList();
        list.traverseLinkedList();

    }

}
