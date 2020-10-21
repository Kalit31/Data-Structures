#include <bits/stdc++.h>
using namespace std;

//Type: Binary search

//Approach: Implementation
//Complexity: O(lgN) time

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (nums.size() == 0)
        {
            return -1;
        }
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        int start = l;
        l = 0;
        r = nums.size() - 1;

        if (target >= nums[start] && target <= nums[r])
        {
            l = start;
        }
        else
        {
            r = start;
        }

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (nums.size() == 0)
        {
            return -1;
        }

        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] >= nums[l])
            {
                if (target >= nums[l] && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (target <= nums[r] && target > nums[mid])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
