#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int ptr1 = 0;
        int ptr2 = n - 1;
        int water = 0;
        while (ptr1 < ptr2)
        {
            water = max(water, min(height[ptr1], height[ptr2]) * (ptr2 - ptr1));
            if (height[ptr1] < height[ptr2])
            {
                ptr1++;
            }
            else
            {
                ptr2--;
            }
        }
        return water;
    }
};