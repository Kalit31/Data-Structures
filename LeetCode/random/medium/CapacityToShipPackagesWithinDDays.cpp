#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(vector<int> &weights, int D, int w)
    {
        int days = 0;
        int currSum = 0;
        int n = weights.size();
        for (int i = 0; i < n; i++)
        {
            if (currSum + weights[i] <= w)
            {
                currSum += weights[i];
            }
            else
            {
                i--;
                currSum = 0;
                days++;
            }
        }
        if (days < D)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int shipWithinDays(vector<int> &weights, int D)
    {
        int maxWeight = INT_MIN;
        int totalWeights = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            totalWeights += weights[i];
            if (maxWeight < weights[i])
            {
                maxWeight = weights[i];
            }
        }
        int l = maxWeight;
        int r = totalWeights;
        int ans = 0;
        while (l <= r)
        {
            int w = l + (r - l) / 2;
            if (isValid(weights, D, w))
            {
                ans = w;
                r = w - 1;
            }
            else
            {
                l = w + 1;
            }
        }
        return ans;
    }
};