#include <bits/stdc++.h>
using namespace std;

//Type: BinarySearch
//Approach: Apply std binary search
//Complexity: O(LgN) time

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int size = nums.size();
        int l = 0;
        int h = size - 1;

        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
        return l;
    }
};

//O(N) time complexity
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (target == nums[i])
            {
                return i;
            }
            if (target < nums[i])
            {
                return i;
            }
        }
        return size;
    }
};