#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Pointers
//Approach: We must observe that there n+1 elements in array.
//          Each element lies b/w 1 to n.
//          So, we could consider each element pointing to an
//          index equal to it's value. In such a case,
//          since a duplicate number exists, there must be a cycle present in the list.
//          The loop would start with the duplicate number.
//          Now, we may simply apply the hare-tortoise algo to find the start of loop.

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int slowPtr = nums[0];
        int fastPtr = nums[0];
        do
        {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        } while (slowPtr != fastPtr);

        slowPtr = nums[0];
        while (slowPtr != fastPtr)
        {
            slowPtr = nums[slowPtr];
            fastPtr = nums[fastPtr];
        }
        return slowPtr;
    }
};