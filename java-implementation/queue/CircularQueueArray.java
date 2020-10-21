package queue;

public class CircularQueueArray {
    int arr[];
    int topOfQueue;
    int start;

    public CircularQueueArray(int size){
        arr = new int[size];
        topOfQueue = -1;
        start = -1;
        System.out.println("Successfully created an empty queue of size: "+size);
    }

    void enQueue(int value){
        if(isQueueFull()){
            System.out.println("Queue overflow error!!");
        }else{
            initializeStartOfArray();
            if(topOfQueue+1==arr.length){
                topOfQueue=0;
            }else{
                topOfQueue++;
            }
            arr[topOfQueue] = value;
            System.out.println("\nSuccessfully inserted "+value+" in the queue");
        }
    }

    void deQueue(){
        if (isQueueEmpty()) {
            System.out.println("Queue underflow error!!");
        }else{
            System.out.println("\n---------------------------------------------");
            System.out.println("Before Dequeue..");printArray();
            System.out.println("\nDequeing value from Queue...");
            System.out.println("Dequeued: "+arr[start]+" from queue");
            arr[start] = 0;
            if(start == topOfQueue)
                start = topOfQueue = -1;
            else if(start == arr.length+1)
                start = 0;
            else
                start++;
        }
        System.out.println("After Dequeue..");
        printArray();
        System.out.println("---------------------------------------------");
    }

    public void initializeStartOfArray() {
        if (start == -1) {
            start = 0;
        }
    }

    boolean isQueueEmpty(){
        if(topOfQueue==-1)
            return true;
        else
            return false;
    }

    public boolean isQueueFull() {
        if (start == topOfQueue+1) {
            return true;
        } else if((start==0)&&(topOfQueue==arr.length-1)) {
            return true;
        }else{
            return false;
        }
    }

    public void peekOperation() {
        if (!isQueueEmpty()) {
            System.out.println("\nPeeking value from queue...");
            System.out.println(arr[start]);
        }else {
            System.out.println("The queue is empty!!");
        }
    }

    public void deleteStack() {
        System.out.println("\n\nDeleting the entire Queue...");
        arr = null;
        System.out.println("Queue is successfully deleted !");
    }

    public void printArray() {
        System.out.println("Array now...");
        for(int i=0; i<arr.length; i++) {
            System.out.print(arr[i]+"  ");
        }
        System.out.println("\nStart = " + start);
        System.out.println("End = "+ topOfQueue);
    }
}
