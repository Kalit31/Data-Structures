package queue;

import linkedList.SingleLinkedList;


public class QueueLinkedList {

    SingleLinkedList list;

    public QueueLinkedList(){
        list = new SingleLinkedList();
    }

    public void enQueue(int value){
        if(list.getHead()==null) {
            list.createSingleLinkedList(value);
        }else{
            list.insertValue(value,list.getSize());
        }
    }

    public int deQueue(){
        int value = -1;
        if(isQueueEmpty()){
            System.out.println("Queue underflow error!!");
        }else{
            value = list.getHead().getValue();
            list.deletionOfNode(0);
        }
        return value;
    }

    public int peek(){
        if(!isQueueEmpty()){
            return list.getHead().getValue();
        }else{
            System.out.println("The queue is empty!!");
            return -1;
        }
    }

    public boolean isQueueEmpty() {
        if (list.getHead() == null)
            return true;
        else
            return false;
    }

    public void deleteStack() {
        list.setHead(null);
        list.setTail(null);
    }
}
