
import java.util.HashMap;
import java.util.Set;

class Solution3 {
    public int majorityElement(int[] nums) {

        if (nums == null || nums.length == 0) {
            return 0;
        }
        return majorityElement(nums, 0);
    }

    private int majorityElement(int[] nums, int start) {
        int count = 1;
        int num = nums[start];
        for (int i = start + 1; i < nums.length; i++) {
            if (num == nums[i])
                count++;
            else
                count--;
            if (count == 0)
                return majorityElement(nums, i + 1);
        }
        return num;
    }
}

class Solution2 {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer majorElement = null;

        for (int num : nums) {
            if (count == 0) {
                majorElement = num;
            }
            count += (num == majorElement) ? 1 : -1;
        }

        return majorElement;

    }
}

class Solution1 {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        Set<Integer> keys = map.keySet();
        for (int k : keys) {
            if (map.get(k) > (n / 2)) {
                return k;
            }
        }
        return 0;
    }
}
