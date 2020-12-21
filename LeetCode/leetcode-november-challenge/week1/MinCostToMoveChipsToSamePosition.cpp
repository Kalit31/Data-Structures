#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostToMoveChips(vector<int> &position)
    {
        int n = position.size();
        int cost1 = 0;
        int cost2 = 0;

        for (int i = 0; i < n; i++)
        {
            if ((position[i]) % 2 == 0)
            {
                cost1++;
            }
            else
            {
                cost2++;
            }
        }
        return min(cost1, cost2);
    }
};