package sorting.selection;

public class SelectionSort {
    public static void selectionSort(int[] arr){
       int n = arr.length;
       for(int i=0;i<n;i++){
           int min = i;
            for(int j=i;j<n;j++){
                if(arr[min]>arr[j]){
                    min = j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i]= temp;
       }
    }

    public static void printArray(int arr[]){
        for(int i =0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
