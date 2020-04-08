
public class MoveZeros {
    public static void moveZeroes(int[] nums) {
        int nonZeroIndex = 0;
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                count++;
                continue;
            }
            nums[nonZeroIndex++] = nums[i];
        }

        for (int i = nums.length - count; i < nums.length; i++) {
            nums[i] = 0;
        }
    }

    public static void main(String args[]) {
        int[] arr = { 0, 1, 0, 3, 12 };
        moveZeroes(arr);
    }
}