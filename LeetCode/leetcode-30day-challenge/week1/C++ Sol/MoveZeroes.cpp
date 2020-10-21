#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Pointers

//Approach: We would start by traversing the array and
//          maintain a pointer to the last non-zero number in the updated array.
//          If we encounter a 0, we will simply skip it,
//          else we would move the non-zero number from the current index
//          to the last-non zero number index.
//          At the end, we would know, the remaining elements till the end of the array
//          are zeros, so simply populate it with zeros.
//Complexity: O(N) time and O(1) space

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        int nonZeroIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            nums[nonZeroIndex++] = nums[i];
        }

        for (int i = nonZeroIndex; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};