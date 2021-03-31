#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumConsecutive(vector<int> &coins)
    {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int ans = 1;
        if (coins[0] != 1)
            return ans;
        int sumTillNow = 1;
        int nextToForm = 2;
        int canForm = 1;
        for (int i = 1; i < n; i++)
        {
            if (nextToForm < coins[i])
                break;
            canForm = max(canForm, coins[i] + sumTillNow);
            sumTillNow += coins[i];
            nextToForm = canForm + 1;
        }
        return canForm + 1;
    }
};