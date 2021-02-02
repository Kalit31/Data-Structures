#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return;
        }
        if (n == 2)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        bool isDesc = true;
        int i;
        for (i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                isDesc = false;
                break;
            }
        }
        if (isDesc)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        int j;
        for (j = n - 1; j > i; j--)
        {
            if (nums[j] > nums[i])
            {
                swap(nums[j], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

//Faster but same logic
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 1;

        // Find number which is to left of the current number and smaller than it
        while (i > 0 and nums[i] <= nums[i - 1])
            i--;

        // If no such number then entire array is in descending order
        if (i == 0)
            reverse(nums.begin(), nums.end());

        else
        {
            i--; // To get the correct position of the smaller number to the left

            int j = nums.size() - 1;

            // Find the next largest number than the number at ith position and swap both of them
            while (nums[j] <= nums[i])
                j--;

            swap(nums[i], nums[j]);

            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};