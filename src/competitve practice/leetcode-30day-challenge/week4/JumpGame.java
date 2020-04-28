class Solution {
    public boolean canJump(int[] nums) {
        if (nums[0] == 0)
            if (nums.length == 1)
                return true;
            else
                return false;

        int maxVal = nums[0];
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (maxVal <= nums[i]) {
                    maxVal = nums[i];
                    continue;
                }
                maxVal--;
                continue;
            } else {
                if (i == nums.length - 1)
                    continue;

                if (maxVal > 0) {
                    maxVal--;
                    if (maxVal == 0)
                        return false;
                    continue;
                }

                return false;
            }
        }
        return true;
    }
}