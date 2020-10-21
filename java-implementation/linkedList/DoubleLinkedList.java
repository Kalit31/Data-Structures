package linkedList;

import node.DoubleNode;

public class DoubleLinkedList {

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

    DoubleNode createDoubleLinkedList(int nodeValue){
        head = new DoubleNode();
        DoubleNode node = new DoubleNode();
        node.setValue(nodeValue);
        node.setNext(null);
        node.setPrev(null);
        head = node;
        tail = node;
        size = 1;
        return head;
    }

    void insertValue(int nodeValue,int location){
        DoubleNode node = new DoubleNode();
        node.setValue(nodeValue);
        if(!existLinkedList()) {
            System.out.println("LinkedList does not exist");
            return;
        }else if(location == 0){
            node.setNext(head);
            node.setPrev(null);
            head.setPrev(node);
            head = node;
            setSize(getSize()+1);
        }else if(location >= size){
            node.setNext(null);
            tail.setNext(node);
            node.setPrev(tail);
            tail = node;
            setSize(getSize()+1);
        }else{
            DoubleNode temp = node;
            for(int i=0;i<location-1;i++){
                temp = temp.getNext();
            }
            node.setNext(temp.getNext());
            node.setPrev(temp);
            temp.getNext().setPrev(node);
            temp.setNext(node);
            setSize(getSize()+1);
        }
    }

    boolean existLinkedList(){
        return head!=null;
    }

    void traverseLinkedList(){
        if(existLinkedList()){
            DoubleNode tempNode=head;
            while(tempNode.getNext()!=null){
                System.out.print(tempNode.getValue()+" -> ");
                tempNode = tempNode.getNext();
            }
          System.out.println(tempNode.getValue());
        }else
            System.out.println("LinkedList does not exists\n");
    }

    void traverseLinkedListInReverseOrder(){
        if(existLinkedList()){
              DoubleNode temp = tail;
              while(temp.getPrev()!=null){
                  System.out.print(temp.getValue()+" <- ");
                  temp = temp.getPrev();
              }
              System.out.println(temp.getValue());
        }else
            System.out.println("LinkedList does not exists\n");
    }

    void deleteNode(int location){
        if(!existLinkedList()){
            System.out.println("LinkedList does not exists\n");
            return;
        }else if(location==0){
            if(getSize()==1){
                head = tail = null;
                setSize(getSize()-1);
                return;
            }
            head = head.getNext();
            head.getPrev().setNext(null);
            head.setPrev(null);
            setSize(getSize()-1);
        }else if(location>=size){
            tail = tail.getPrev();
            if(tail == head){
                tail = head = null;
                setSize(getSize()-1);
                return;
            }
            tail.getNext().setPrev(null);
            tail.setNext(null);
            setSize(getSize()-1);
        }else{
            DoubleNode temp = head;
            for(int i = 0;i<location-1;i++){
                temp = temp.getNext();
            }
            temp.setNext(temp.getNext().getNext());
            if(temp.getNext()!=null)
                temp.getNext().setPrev(temp);
            else
                tail = temp;
            setSize(getSize()-1);
        }
    }

    void deleteList(){
        System.out.println("Deleting LinkedList...");
        DoubleNode temp = head;
        for(int i=0;i<getSize();i++){
            temp.setPrev(null);
            temp = temp.getNext();
        }
        head = tail = null;
        System.out.println("LinkedList deleted!");
    }

    boolean searchNode(int nodeValue){
        if(existLinkedList()){
            DoubleNode temp = head;
            for(int i =0;i<size;i++){
                if(temp.getValue() == nodeValue){
                    System.out.println("Node found!");
                    return true;
                }
                temp = temp.getNext();
            }
            System.out.println("Not found");
        }else
            System.out.println("LinkedList does not exist");
        return true;
    }

}
