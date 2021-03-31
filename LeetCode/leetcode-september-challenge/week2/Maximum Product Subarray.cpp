#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int maxProd = nums[0];
        int currMinProd = nums[0];
        int currMaxProd = nums[0];

        for (int i = 1; i < n; i++)
        {
            int t = currMinProd;
            currMinProd = min(currMinProd * nums[i], min(currMaxProd * nums[i], nums[i]));
            currMaxProd = max(t * nums[i], max(currMaxProd * nums[i], nums[i]));
            maxProd = max(maxProd, currMaxProd);
        }
        return maxProd;
    }
};