#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minP = INT_MAX;
        int maxP = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < minP)
            {
                minP = prices[i];
            }
            else
            {
                maxP = max(maxP, prices[i] - minP);
            }
        }
        return maxP;
    }
};