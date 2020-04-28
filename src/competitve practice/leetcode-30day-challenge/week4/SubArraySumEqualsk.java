
class Solution {
    public int subarraySum(int[] nums, int k) {
        long sumArr[] = new long[nums.length];
        sumArr[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            sumArr[i] = sumArr[i - 1] + nums[i];
        }

        int count = 0;
        HashMap<Long, Integer> sumMap = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (sumArr[i] == k) {
                count++;
            }
            if (sumMap.containsKey(sumArr[i] - k)) {
                count += sumMap.get(sumArr[i] - k);
            }

            sumMap.put(sumArr[i], sumMap.getOrDefault(sumArr[i], 0) + 1);

        }
        return count;
    }
}

class Solution2 {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer, Integer> sumMap = new HashMap<Integer, Integer>();
        sumMap.put(0, 1);
        int count = 0;
        int sum = 0;

        for (int i = 0; i < nums.length; i++) {
            sum = sum + nums[i];
            if (sumMap.containsKey(sum - k)) {
                count = count + sumMap.get(sum - k);
            }
            sumMap.put(sum, sumMap.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}