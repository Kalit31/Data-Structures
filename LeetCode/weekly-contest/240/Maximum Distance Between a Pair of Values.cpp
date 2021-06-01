#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int ptr1 = 0;
        int ptr2 = 0;

        int maxDist = 0;

        while (ptr1 < n1)
        {
            while (ptr2 < (n2 - 1) && nums2[ptr2 + 1] >= nums1[ptr1])
            {
                ptr2++;
            }
            maxDist = max(maxDist, ptr2 - ptr1);
            ptr1++;
        }

        return maxDist;
    }
};