package sorting.insertion;

public class InsertionSort {
    public static void insertionSort(int[] arr){
        int n = arr.length;
        for(int i = 1;i<n;i++){
            int currentNumber = arr[i];
            int j=i;
            while(j>0&&arr[j-1]>currentNumber){
                arr[j]=arr[j-1];
                j--;
            }
            arr[j] = currentNumber;
        }
    }

    public static void printArray(int[] arr){
        for(int i =0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }

}
