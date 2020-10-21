package linkedList;

import node.SingleNode;

public class SingleLinkedList {
       private SingleNode head=null;
       private SingleNode tail=null;
       private int size;

       public SingleNode createSingleLinkedList(int nodeValue){
            SingleNode node = new SingleNode();
            node.setValue(nodeValue);
            node.setNext(null);
            head = node;
            tail = node;
            size = 1;
            return head;
       }

       public SingleNode getHead(){
           return head;
       }

       public void setHead(SingleNode node){
           this.head = node;
       }

       public SingleNode getTail(){
           return tail;
       }
       public void setTail(SingleNode node){
           this.tail = node;
       }
       public int getSize(){
           return size;
       }
       public void setSize(int size){
           this.size = size;
       }

       public void insertValue(int nodeValue, int location){
           SingleNode node = new SingleNode();
           node.setValue(nodeValue);
           if(!existsLinkedList()){
               System.out.println("LinkedList does not exist");
               return;
           }else if(location == 0) {
               node.setNext(head);
               head = node;
           }else if(location >= size){
               node.setNext(null);
               tail.setNext(node);
               tail = node;
           }else{
               SingleNode temp = head;
               int index = 0;
               while(index < location-1){
                   temp = temp.getNext();
                   index++;
               }
               SingleNode nextNode = temp.getNext();
               temp.setNext(node);
               node.setNext(nextNode);
           }
           this.setSize(this.getSize() + 1);
       }
       public boolean existsLinkedList(){
           return head!=null;
       }

       void traverseLinkedList(){
           if(existsLinkedList()){
               SingleNode temp = head;
              for(int i = 0;i< this.getSize();i++){
                   System.out.print(temp.getValue());
                   if(i != getSize()-1)
                       System.out.print(" -> ");
                   temp = temp.getNext();
               }
           }else
               System.out.println("Linked List does not exist!");
            System.out.println();
       }

       public void deletionOfNode(int location){
           if(!existsLinkedList()){
               System.out.println("LinkedList does not exist");
               return;
           }else if(location == 0){
               head = head.getNext();
               setSize(getSize()-1);
               if(getSize() == 0){
                   tail = null;
               }
           }else if(location >= getSize()){
               SingleNode temp = head;
               for(int i = 0 ;i<size-1;i++){
                   temp = temp.getNext();
               }
               if(temp == head){
                   tail = head = null;
                   setSize(getSize()-1);
                   return;
               }
               temp.setNext(null);
               tail = temp;
               setSize(getSize()-1);
           }else{
               SingleNode temp = head;
               for(int i = 0;i< location-1;i++){
                   temp = temp.getNext();
               }
               temp.setNext(temp.getNext().getNext());
               setSize(getSize()-1);
           }
       }

       void deleteLinkedList(){
           System.out.println("Deleting Linked List....");
           head = null;
           tail = null;
           System.out.println("Deleted Linked List successfully ...");
       }

       boolean searchNode(int nodeValue){
           SingleNode temp = head;
           while(temp.getNext()!=null){
               if(temp.getValue() == nodeValue){
                   System.out.println("Found node");
                   return true;
               }
               temp = temp.getNext();
           }
           System.out.println("Node not found");
           return false;
       }

}
