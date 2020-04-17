import java.util.*;

class Solution1 {
    public int findMaxLength(int[] nums) {

        int[] arr = new int[2 * nums.length + 1];
        Arrays.fill(arr, -2);
        arr[nums.length] = -1;
        int maxlen = 0, count = 0;
        for (int i = 0; i < nums.length; i++) {
            count = count + (nums[i] == 0 ? -1 : 1);
            if (arr[count + nums.length] >= -1) {
                maxlen = Math.max(maxlen, i - arr[count + nums.length]);
            } else {
                arr[count + nums.length] = i;
            }
        }
        return maxlen;
    }
}

class Solution2 {
    public int findMaxLength(int[] nums) {
        int sum = 0;
        int longestSubarray = 0;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i = 0; i < nums.length; i++) {
            sum += nums[i] == 1 ? 1 : -1;

            if (sum == 0) {
                if (longestSubarray < i + 1)
                    longestSubarray = i + 1;
            } else if (map.containsKey(sum)) {
                if (longestSubarray < i - map.get(sum)) {
                    longestSubarray = i - map.get(sum);
                }
            } else {
                map.put(sum, i);
            }
        }

        return longestSubarray;
    }
}