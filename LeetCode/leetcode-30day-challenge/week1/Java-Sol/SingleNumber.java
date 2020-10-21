//Brute force startegy : Create a hashmap storing the frequency of each element,
//                       and then traverse through it to find the element with
//                       frequency equal to 1.
//Complexity : O(N) time and space complexity.

//Optimized approach : Use the property of XOR. Applying XOR operation on two same
//                     numbers is 0, and any number XOR 0 gives back the number.
//                     So, we could traverse the array and find the XOR of all elements.
//                     The final result would yield us the number with frequency 1.
//Complexity : O(N) time complexity and O(1) space complexity.

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