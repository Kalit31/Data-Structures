#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int ptr1 = 0;
        int ptr2 = 0;

        while (ptr1 < n && ptr2 < m)
        {
            if (nums1[ptr1] == nums2[ptr2])
            {
                result.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if (nums1[ptr1] < nums2[ptr2])
            {
                ptr1++;
            }
            else
            {
                ptr2++;
            }
        }
        return result;
    }
};