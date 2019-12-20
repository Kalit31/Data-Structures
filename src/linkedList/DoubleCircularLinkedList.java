package linkedList;

import node.DoubleNode;

public class DoubleCircularLinkedList {
    DoubleNode head;
    DoubleNode tail;
    int size;

    public DoubleNode getHead() {
        return head;
    }

    public void setHead(DoubleNode head) {
        this.head = head;
    }

    public DoubleNode getTail() {
        return tail;
    }

    public void setTail(DoubleNode tail) {
        this.tail = tail;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    DoubleNode createDoubleCircularList(int nodeValue){
        DoubleNode node = new DoubleNode();
        head = new DoubleNode();
        node.setValue(nodeValue);
        node.setNext(node);
        node.setPrev(node);
        head = tail = node;
        size=1;
        return head;
    }

    void insertValue(int nodeValue,int location){
        DoubleNode node = new DoubleNode();
        node.setValue(nodeValue);
        if (!existLinkedList()) {
            System.out.println("The linked list does not exist!!");
            return;
        } else if (location == 0) {
            node.setNext(head);
            node.setPrev(tail);
            head.setPrev(node);
            tail.setNext(node);
            head = node;
        } else if (location >= size) {
            node.setNext(head);
            node.setPrev(tail);
            head.setPrev(node);
            tail.setNext(node);
            tail = node;
        } else {
            DoubleNode tempNode = head;
            int index = 0;
            while (index < location - 1) {
                tempNode = tempNode.getNext();
                index++;
            }
            node.setPrev(tempNode);
            node.setNext(tempNode.getNext());
            tempNode.setNext(node);
            node.getNext().setPrev(node);
        }
        size++;
    }

    void traverseLinkedList() {
        if (existLinkedList()) {
            DoubleNode tempNode = head;
            for (int i = 0; i < size; i++) {

                System.out.print(tempNode.getValue());
                if (i != size - 1) {
                    System.out.print(" -> ");
                }
                tempNode = tempNode.getNext();
            }
        }else {
            System.out.println("Linked List does not exists !");
        }
        System.out.println();
    }

    void traverseLinkedListInReverseOrder() {
        if (existLinkedList()) {
            DoubleNode tempNode = tail;
            System.out.println("\nPrinting Linked list in reverse order...");
            for (int i = 0; i < size; i++) {
                System.out.print(tempNode.getValue());
                if (i != size-1) {
                    System.out.print(" <- ");
                }
                tempNode = tempNode.getPrev();
            }
        } else {
            System.out.println("Linked List does not exists !");
        }
    }

    void deleteLinkedList() {
        System.out.println("\n\nDeleting Linked List...");
        if (tail == null) {
            System.out.println("Linked List is already deleted, nothing to delete anymore !");
            return;
        }else {
            head.setPrev(null);
            tail.setNext(null);
            head = null;
            tail = null;
            System.out.println("Linked List deleted successfully !");
        }
    }

    boolean searchNode(int nodeValue) {
        if (existLinkedList()) {
            DoubleNode tempNode = head;
            traverseLinkedList();
            for (int i = 0; i < size; i++) {
                if (tempNode.getValue() == nodeValue) {
                    System.out.print("Found the node at location: " + i);
                    return true;
                }
                tempNode = tempNode.getNext();
            }
        }
        System.out.print("Node not found!! ");
        return false;
    }

    public void deletionOfNode(int location) {
        if (!existLinkedList()) {
            System.out.println("The linked list does not exist!!");
            return;
        } else if (location == 0) {
            if (getSize() == 1) {
                head.setNext(null);
                head.setPrev(null);
                head = tail = null;
                setSize(getSize() - 1);
                return;
            }else {
                head = head.getNext();
                head.setPrev(null);
                tail.setNext(head);
                setSize(getSize() - 1);
            }
        } else if (location >= getSize()) {
            if (getSize() == 1) {
                head.setNext(null);
                head.setPrev(null);
                tail = head = null;
                setSize(getSize() - 1);
                return;
            }
            tail = tail.getPrev();
            tail.setNext(head);
            head.setPrev(tail);
            setSize(getSize() - 1);
        } else {
            DoubleNode tempNode = head;
            for (int i = 0; i < location - 1; i++) {
                tempNode = tempNode.getNext();
            }
            tempNode.setNext(tempNode.getNext().getNext());
            tempNode.getNext().setPrev(tempNode);
            setSize(getSize() - 1);
        }

    }

    boolean existLinkedList(){
        return head!=null;
    }
}
