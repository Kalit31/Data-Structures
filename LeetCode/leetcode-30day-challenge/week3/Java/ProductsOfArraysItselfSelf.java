class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] finalOutput = new int[nums.length];
        finalOutput[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            finalOutput[i] = nums[i - 1] * finalOutput[i - 1];
        }
        int temp = 1;
        for (int i = nums.length - 2; i >= 0; i--) {
            temp = temp * nums[i + 1];
            finalOutput[i] = finalOutput[i] * temp;
        }

        return finalOutput;
    }
}