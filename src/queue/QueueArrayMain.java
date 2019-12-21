package queue;

public class QueueArrayMain {
    public static void main(String[] args) {

        System.out.println("Creating an empty queue...");
        QueueArray queue = new QueueArray(5);

        System.out.println("Enqueuing 6 values in the queue...");
        for (int i = 1; i <= 6; i++) {
            queue.enQueue(i * 10);
        }

        System.out.println("Peek value from queue...");
        queue.peekOperation();

        System.out.println("Dequeue 6 values from queue...");
        for (int i = 0; i <= 5; i++) {
            queue.deQueue();
        }

        System.out.println("Deleting the entire Queue...");
        queue.deleteQueue();

    }
}
