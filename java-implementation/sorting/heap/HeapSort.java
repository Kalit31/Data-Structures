package sorting.heap;

import heap.Heap;

public class HeapSort {
    int[] arr;

    public HeapSort(int[] arr) {
        this.arr = arr;
    }

    public void sort(){
        Heap heap = new Heap(arr.length);
        for(int i=0;i<arr.length;i++)
            heap.insertInHeap(arr[i]);
        for(int i=0;i<arr.length;i++)
            arr[i] = heap.extractHeadOfHeap();
    }

    public void printArray() {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+"  ");
        }
    }
}
