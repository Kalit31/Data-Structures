package linkedList;

import node.SingleNode;

public class SingleCircularLinkedList {
    private SingleNode head;
    private SingleNode tail;
    private int size;

    SingleNode createSingleCircularLinkedList(int nodeValue){
        head = new SingleNode();
        SingleNode node = new SingleNode();
        node.setValue(nodeValue);
        node.setNext(node);
        head = node;
        tail = node;
        size = 1;
        return head;
    }

    public SingleNode getHead() {
        return head;
    }

    public void setHead(SingleNode head) {
        this.head = head;
    }

    public SingleNode getTail() {
        return tail;
    }

    public void setTail(SingleNode tail) {
        this.tail = tail;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    void insertValue(int nodeValue,int location){
        SingleNode node = new SingleNode();
        node.setValue(nodeValue);
        System.out.println("Inserting new node at location: " + location);
        if(!existsLinkedList()){
            System.out.println("Linked list does not exist!");
        }else if(location == 0){
            node.setNext(head);
            head = node;
            tail.setNext(node);
        }else if(location>=size){
            tail.setNext(node);
            tail = node;
            node.setNext(head);
        }else{
            SingleNode temp = head;
            int i = 0;
            while(i<location-1){
                temp = temp.getNext();
                i++;
            }
            node.setNext(temp.getNext());
            temp.setNext(node);
        }
        size++;
    }

    public boolean existsLinkedList() {
        // if head is not null retrun true otherwise return false
        return head != null;
    }

    void traverseLinkedList(){
        if(existsLinkedList()){
            SingleNode temp = head;
            for(int i =0;i<getSize();i++){
                System.out.print(temp.getValue());
                if(i != size-1)
                    System.out.print(" -> ");
                temp = temp.getNext();
            }
            System.out.println();
        }else
            System.out.println("Linked List does not exist");
    }

    boolean searchNode(int nodeValue){
        if(existsLinkedList()){
            SingleNode temp = head;
            for(int i =0;i<size;i++){
                if(temp.getValue()==nodeValue){
                    System.out.println("Node found");
                    return true;
                }
                temp = temp.getNext();
            }
        }else
            System.out.println("LinkedList does not exist");
        return false;
    }

    void deleteNode(int location){
        if(!existsLinkedList())
        {
            System.out.println("LinkedList does not exist");
            return;
        }else if(location == 0){
            head = head.getNext();
            tail.setNext(head);
            setSize(getSize()-1);
            if(getSize()==0)
                tail = null;
        }else if(location >= size){
            SingleNode temp = head;
            for(int i = 0;i<size-1;i++){
                temp = temp.getNext();
            }
            if(temp == head){
                tail = head = null;
                setSize(getSize()-1);
                return;
            }
            tail = temp;
            tail.setNext(head);
            setSize(getSize()-1);
        }else{
            SingleNode temp = head;
            for(int i=0;i<location-1;i++){
                temp = temp.getNext();
            }
            temp.setNext(temp.getNext().getNext());
            setSize(getSize()-1);
        }
    }

    void deleteLinkedList(){
            System.out.println("Deleting LinkedList...");
            head = null;
            if(tail == null){
                System.out.println("Linked List is already deleted, nothing to delete !");
                return;
            }else{
                tail.setNext(null);
                tail = null;
                System.out.println("Linked List deleted successfully !");
            }
    }

    void printHeadUsingTail(){
        if(existsLinkedList()){
            System.out.println("Printing Tail...");
            System.out.println(tail.getValue());
            System.out.println("Printing Head using Head reference...");
            System.out.println(head.getValue());
            System.out.println("Printing Head using Tail reference...");
            System.out.println(tail.getNext().getValue());
        }else
            System.out.println("Linked List does not exists");
    }

}
