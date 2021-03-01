#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while (low <= high)
        {
            int partX = (low + high) / 2;
            int partY = (n1 + n2 + 1) / 2 - partX;

            int maxleftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
            int minrightX = (partX == n1) ? INT_MAX : nums1[partX];

            int maxleftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
            int minrightY = (partY == n2) ? INT_MAX : nums2[partY];

            if (maxleftX <= minrightY && maxleftY <= minrightX)
            {
                if ((n1 + n2) % 2 == 0)
                    return (double)(max(maxleftX, maxleftY) + min(minrightX, minrightY)) / 2;
                else
                    return (double)(max(maxleftX, maxleftY));
            }
            else if (maxleftX > minrightY)
            {
                high = partX - 1;
            }
            else if (maxleftY > minrightX)
            {
                low = partX + 1;
            }
        }
        return 0;
    }
};