package stack;

import linkedList.SingleLinkedList;

public class StackLinkedList {
    SingleLinkedList list;

    public StackLinkedList() {
        list = new SingleLinkedList();
    }

    public void push(int value){
        if(list.getHead()==null)
            list.createSingleLinkedList(value);
        else
            list.insertValue(value,0);
        System.out.println("Inserted " + value + " in Stack !");
    }

    public int pop(){
        int value = -1;
        if(isEmpty())
            System.out.println("Stack underflow error!!");
        else{
            value = list.getHead().getValue();
            list.deletionOfNode(0);
        }
        return value;
    }

    public boolean isEmpty() {
        if(list.getHead() == null)
            return true;
        else
            return false;
    }

    public int peek() {
        if (!isEmpty())
            return list.getHead().getValue();
        else {
            System.out.println("The stack is empty!!");
            return -1;
        }
    }

    public void deleteStack() {
        list.setHead(null);
    }
}