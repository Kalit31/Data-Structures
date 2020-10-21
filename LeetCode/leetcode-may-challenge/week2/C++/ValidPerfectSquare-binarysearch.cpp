#include <bits/stdc++.h>
using namespace std;

//Type: Binary Search
//Approach: Fix the bounds appropriately and apply the standard algo
//Complexity: O(lg(100000)) which can be thought of as O(1) time

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int high = 100000;
        int low = 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long int s = (long int)mid * (long int)mid;
            if (s == num)
                return true;
            else if (s < num)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};