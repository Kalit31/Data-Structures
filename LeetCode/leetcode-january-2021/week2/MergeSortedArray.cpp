#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        int mn = nums1.size();
        int i = mn - 1;

        while (ptr1 >= 0 && ptr2 >= 0)
        {
            int n1 = nums1[ptr1];
            int n2 = nums2[ptr2];
            if (n1 < n2)
            {
                nums1[i--] = nums2[ptr2--];
            }
            else
            {
                nums1[i--] = nums1[ptr1--];
            }
        }
        while (ptr2 >= 0)
        {
            nums1[i--] = nums2[ptr2--];
        }
    }
};