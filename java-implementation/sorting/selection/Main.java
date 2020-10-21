package sorting.selection;

public class Main {
    public static void main(String[] args) {
        int array[] = {10, 3, 2, 5, 8, 4, 3, 1, 2, 9, 7, 8};

        System.out.println("User entered Array: ");
        SelectionSort.printArray(array);

        long start = System.nanoTime();
        SelectionSort.selectionSort(array);
        long end = System.nanoTime();
        System.out.println("\n\nTime to execute this algo: " + (end-start));

        System.out.println("\n\nAfter sorting: ");
        SelectionSort.printArray(array);
    }
}
