#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Pointers
//Approach: Maintain two pointers corresponding to sequence of 0's and 2's
//          Start traversing the array. As we encounter a 0,
//          we swap it with the position pointed by ptr1 and increment ptr1
//          If we encounter a 2, we swap it with the position pointed by ptr2 and decrement it.
//Complexity: O(N) time

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int size = nums.size();
        int ptr1 = 0;
        int ptr2 = size - 1;

        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
            {
                if (i == ptr1)
                {
                    continue;
                }
                swap(nums[i], nums[ptr1]);
                ptr1++;
                i--;
            }
            else if (nums[i] == 2)
            {
                if (i >= ptr2)
                {
                    break;
                }
                swap(nums[i], nums[ptr2]);
                ptr2--;
                i--;
            }
        }
    }
};