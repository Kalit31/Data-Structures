class SingleNumber {
    public static int singleNumber(int[] nums) {
        int result = 0;
        for (int n : nums) {
            result = result ^ n;
        }
        return result;
    }

    public static void main(String args[]) {
        int[] arr = { 4, 1, 2, 1, 2 };
        System.out.println(singleNumber(arr));
    }

}