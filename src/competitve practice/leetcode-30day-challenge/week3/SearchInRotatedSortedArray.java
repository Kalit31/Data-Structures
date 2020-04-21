class Solution1 {
    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        if (nums.length == 0)
            return -1;
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[left]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else
                    left = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else
                    right = mid - 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
}

class Solution2 {
    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        int mid;

        if (nums == null || nums.length == 0)
            return -1;

        while (r > l) {
            mid = (l + r) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        int start = l;
        l = 0;
        r = nums.length - 1;

        if (target >= nums[start] && target <= nums[r]) {
            l = start;
        } else {
            r = start;
        }

        while (r >= l) {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return -1;
    }
}