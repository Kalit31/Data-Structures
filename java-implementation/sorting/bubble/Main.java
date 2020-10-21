package sorting.bubble;

public class Main {
    public static void main(String[] args) {

        BubbleSort ob = new BubbleSort();
        int arr[] ={10, 3, 2, 5, 8, 4, 3, 1, 2, 9, 7, 8};
        System.out.println("Array to be sorted...");
        ob.printArray(arr);

        long start = System.nanoTime();
        ob.bubbleSort(arr);
        long end = System.nanoTime();
        System.out.println("\n\nTime to execute this algo: " + (end-start));

        System.out.println("Sorted Array...");
        ob.printArray(arr);

    }

}
