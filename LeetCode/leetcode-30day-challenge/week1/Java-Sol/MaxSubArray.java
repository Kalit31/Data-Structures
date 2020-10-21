
public class MaxSubArray {
    public static int maxSubArray(int[] nums) {
        int max = nums[0];
        int sumTillNow = 0;
        for (int i = 0; i < nums.length; i++) {
            sumTillNow = sumTillNow + nums[i];
            max = Math.max(max, sumTillNow);
            sumTillNow = Math.max(sumTillNow, 0);
        }
        return max;
    }

    public static void main(String args[]) {
        int[] arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        System.out.println(maxSubArray(arr));
    }
}