import java.util.Scanner;

public class AlternatingSubsequence {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = in.nextInt();
            int[] arr = new int[n];
            for (int j = 0; j < n; j++) {
                arr[j] = in.nextInt();
            }
            int max = findMaxSum(0, arr, 0);
            System.out.println(max);
        }
        in.close();
    }

    public static int findMaxSum(int sum, int[] arr, int currentIndex) {
        System.out.println("CI " + currentIndex);
        int i = currentIndex;
        if (currentIndex >= arr.length)
            return sum;
        int max = 0;
        if (arr[currentIndex] > 0) {
            while (currentIndex < arr.length && arr[currentIndex] > 0) {
                currentIndex++;
            }
            if (currentIndex == arr.length)
                return sum;
            System.out.println("ARR: " + arr[currentIndex]);
            max = sum + arr[currentIndex] + findMaxSum(sum, arr, currentIndex);
            // int max = Math.max(findMaxSum(sum, arr, i + 1), sum);
        } else {
            while (currentIndex < arr.length && arr[currentIndex] < 0) {
                currentIndex++;
            }
            if (currentIndex == arr.length)
                return sum;

            System.out.println("ARR: " + arr[currentIndex]);
            max = sum + arr[currentIndex] + findMaxSum(sum, arr, currentIndex);
            // int max = Math.max(findMaxSum(sum, arr, i + 1), sum);
        }
        return Math.max(max, findMaxSum(sum, arr, i + 1));
    }
}