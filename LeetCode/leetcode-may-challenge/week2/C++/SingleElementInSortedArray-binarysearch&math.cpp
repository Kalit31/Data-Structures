#include <bits/stdc++.h>
using namespace std;

//Type: Binary Search, Math
//Approach: We shall apply the standard algo. If for a mid value,
//          the mid element is equal to the element left to it:
//          if the number of element from mid to end is even,
//          the req num will lie to the left of num
//          else it would lie to the right
//          Similar logic could be created if the mid element is equal to the element right of it
//Complexity:  o(lgN) time

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == nums[mid - 1])
            {
                if ((r - mid) % 2 == 0)
                {
                    r = mid - 2;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else if (nums[mid] == nums[mid + 1])
            {
                if ((r - mid) % 2 == 0)
                {
                    l = mid + 2;
                }
                else
                {
                    r = mid - 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return nums[l];
    }
};