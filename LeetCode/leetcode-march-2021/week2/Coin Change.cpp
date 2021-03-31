#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> ways(amount + 1, INT_MAX);
        ways[0] = 0;
        for (int i = 0; i <= amount; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i - coins[j] >= 0)
                {
                    if (ways[i - coins[j]] != INT_MAX)
                        ways[i] = min(ways[i], 1 + ways[i - coins[j]]);
                }
            }
        }
        return ways[amount] == INT_MAX ? -1 : ways[amount];
    }
};