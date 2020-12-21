#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculate(vector<int> &days, vector<int> &costs, int index, int limit, unordered_map<int, int> &costMap)
    {
        int numDays = days.size();
        int totalCost = INT_MAX;
        int i;
        for (i = index; i < numDays; i++)
        {
            if (days[i] > limit)
            {
                break;
            }
        }
        if (i == numDays)
        {
            return 0;
        }
        if (costMap.find(i) != costMap.end())
        {
            return costMap[i];
        }
        totalCost = min(totalCost, costs[0] + calculate(days, costs, i + 1, days[i], costMap));
        totalCost = min(totalCost, costs[1] + calculate(days, costs, i + 1, days[i] + 6, costMap));
        totalCost = min(totalCost, costs[2] + calculate(days, costs, i + 1, days[i] + 29, costMap));
        costMap[i] = totalCost;
        return totalCost;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int totalCost = INT_MAX;
        unordered_map<int, int> costMap;
        totalCost = min(totalCost, costs[0] + calculate(days, costs, 1, days[0], costMap));
        totalCost = min(totalCost, costs[1] + calculate(days, costs, 1, days[0] + 6, costMap));
        totalCost = min(totalCost, costs[2] + calculate(days, costs, 1, days[0] + 29, costMap));
        return totalCost;
    }
};

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(366, INT_MAX);
        dp[0] = 0;
        int k = 0;
        int p;
        for (int i = 1; i <= days.back(); i++)
        {
            if (days[k] == i)
            {
                p = max(i - 1, 0);
                dp[i] = min(dp[i], dp[p] + costs[0]);
                p = max(i - 7, 0);
                dp[i] = min(dp[i], dp[p] + costs[1]);
                p = max(i - 30, 0);
                dp[i] = min(dp[i], dp[p] + costs[2]);
                k++;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[days.back()];
    }
};

class Solution
{
public:
    int mincostTickets(vector<int> &a, vector<int> &costs)
    {
        int f[366], i;
        bool yes[366];
        for (i = 1; i <= 365; ++i)
            yes[i] = false;
        for (i = 0; i < a.size(); ++i)
            yes[a[i]] = true;
        f[0] = 0;
        for (i = 1; i <= 365; ++i)
        {
            if (!yes[i])
                f[i] = f[i - 1];
            else
                f[i] = 1000000000;
            f[i] = min(f[i], f[max(0, i - 1)] + costs[0]);
            f[i] = min(f[i], f[max(0, i - 7)] + costs[1]);
            f[i] = min(f[i], f[max(0, i - 30)] + costs[2]);
        }
        return f[365];
    }
};