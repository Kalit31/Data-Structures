package linkedList;

public class DoubleLinkedListMain {
    public static void main(String[] args) {
        DoubleLinkedList list = new DoubleLinkedList();
        list.createDoubleLinkedList(5);
        list.traverseLinkedList();

        list.insertValue(10, 1);
        list.traverseLinkedList();

        list.insertValue(20, 2);
        list.traverseLinkedList();

        list.insertValue(30, 3);
        list.traverseLinkedList();

        list.insertValue(40, 4);
        list.traverseLinkedList();

        System.out.println("\nSearching the node having value 40: ");
        list.searchNode(40);

        System.out.println("\n\nSearching the node having value 400: ");
        list.searchNode(400);


        System.out.println("\n\nLinked List in order");
        list.traverseLinkedList();
        System.out.println("Linked List in reverse order");
        list.traverseLinkedListInReverseOrder();


        System.out.println("\n\nDeleting the node having location = 2: ");
        System.out.println("List before deletion: ");
        list.traverseLinkedList();
        list.deleteNode(2);
        System.out.println("List after deletion: ");
        list.traverseLinkedList();


        System.out.println("\n\nDeleting the node having location = 3: ");
        System.out.println("List before deletion: ");
        list.traverseLinkedList();
        list.deleteNode(3);
        System.out.println("List after deletion: ");
        list.traverseLinkedList();


        list.deleteList();
        list.traverseLinkedList();

    }
}
