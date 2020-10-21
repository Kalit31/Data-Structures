#include <bits/stdc++.h>
using namespace std;

//Type: Binary Search
//Approach:
//Complexity: O(lgN) calls to func
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long int low = 1;
        long int high = n;
        while (low <= high)
        {
            long int mid = (low + high) / 2;
            if (isBadVersion(mid))
            {
                if (!isBadVersion(mid - 1))
                    return mid;
                high = mid - 1;
            }
            else
            {
                if (isBadVersion(mid + 1))
                    return mid + 1;
                low = mid + 1;
            }
        }
        return 1;
    }
};

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 1;
        int high = n;
        int ans;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};