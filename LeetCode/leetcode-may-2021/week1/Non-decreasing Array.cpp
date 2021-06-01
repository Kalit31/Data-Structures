#include <bits/stdc++.h>
using namespace std;

//O(N) solution
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                cnt++;
                if (i - 2 < 0 || nums[i - 2] <= nums[i])
                {
                    nums[i - 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
            }
        }

        return cnt <= 1;
    }
};

//O(N^2) soln
class Solution
{
public:
    bool isFine(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        if (isFine(nums))
        {
            return true;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == n - 1)
            {
                nums[i] = nums[i - 1];
                if (isFine(nums))
                {
                    return true;
                }
            }
            else
            {
                int t = nums[i];
                nums[i] = nums[i + 1];
                if (isFine(nums))
                {
                    return true;
                }
                nums[i] = t;
            }
        }
        return false;
    }
};