#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> result(n, 0);

        int posInd = n;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                posInd = i;
                break;
            }
        }
        int negInd = posInd - 1;

        int i = 0;
        while (negInd >= 0 && posInd < n)
        {
            if (abs(nums[posInd]) < abs(nums[negInd]))
            {
                result[i++] = nums[posInd] * nums[posInd];
                posInd++;
            }
            else
            {
                result[i++] = nums[negInd] * nums[negInd];
                negInd--;
            }
        }

        while (negInd >= 0)
        {
            result[i++] = nums[negInd] * nums[negInd];
            negInd--;
        }

        while (posInd < n)
        {
            result[i++] = nums[posInd] * nums[posInd];
            posInd++;
        }

        return result;
    }
};