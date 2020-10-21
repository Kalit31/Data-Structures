package sorting.bucket;

import java.util.ArrayList;
import java.util.Collections;

public class BucketSort {
    int[] arr;

    public BucketSort(int[] arr) {
        this.arr = arr;
    }

    public void bucketSort(){
        int noOfBuckets = (int) Math.ceil(Math.sqrt(arr.length));
        int maxValue = Integer.MIN_VALUE;
        int minValue = Integer.MAX_VALUE;

        for(int value: arr) {
            if(value < minValue) {
                minValue = value;
            }else if (value > maxValue) {
                maxValue = value;
            }
        }

        ArrayList<Integer>[] buckets = new ArrayList[noOfBuckets];
        for(int i =0;i<buckets.length;i++) {
            buckets[i] = new ArrayList<Integer>();
        }

        for(int value: arr) {
            int bucketNumber = (int) Math.ceil ((value *  noOfBuckets) / maxValue);
            buckets[bucketNumber-1].add(value);
        }

        System.out.println("\n\nPrinting buckets before Sorting...");
        printBuckets(buckets);

        for(ArrayList<Integer> bucket: buckets) {
            Collections.sort(bucket);
        }

        System.out.println("\n\nPrinting buckets after Sorting...");
        printBuckets(buckets);

        int index=0;
        for(ArrayList<Integer> bucket: buckets) {
            for(int value: bucket) {
                arr[index] = value;
                index++;
            }
        }
    }

    public void printBuckets(ArrayList<Integer>[] buckets) {
        for(int i=0; i<buckets.length; i++) {
            System.out.println("\nBucket#" + i + " :");
            for (int j=0; j<buckets[i].size(); j++) {
                System.out.print(buckets[i].get(j)+"  ");
            }
        }
    }


    public void printArray(){
        for(int i =0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
