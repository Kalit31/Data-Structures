#include <bits/stdc++.h>
using namespace std;

//Type: Math
//Approach: The important observation here is to understand the parameter we want to minimize.
//          It is how much will we benefit from going to city A rather than city B.
//          We form an array for this parameter and sort in decreasing order.
//          The first half of the elements would go to city A and the rest half to city B.
//Complexity: O(NLgN) time and O(N) space

class Solution
{
public:
    static bool sortdesc(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.first > b.first);
    }

    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<pair<int, int>> profit;
        int N = costs.size();
        for (int i = 0; i < N; i++)
        {
            profit.push_back({costs[i][1] - costs[i][0], i});
        }

        sort(profit.begin(), profit.end(), sortdesc);

        int totalCost = 0;
        for (int i = 1; i <= (N / 2); i++)
        {
            totalCost += costs[profit[i - 1].second][0];
        }

        for (int i = (N / 2) + 1; i <= N; i++)
        {
            totalCost += costs[profit[i - 1].second][1];
        }
        return totalCost;
    }
};

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        vector<int> loss(costs.size(), 0);

        int total_cost = 0;
        for (int i = 0; i < costs.size(); i++)
        {
            total_cost += costs[i][0];
            loss[i] = costs[i][0] - costs[i][1];
        }
        sort(loss.begin(), loss.end(), greater<>());

        for (int i = 0; i < costs.size() / 2; i++)
        {
            total_cost -= loss[i];
        }

        return total_cost;
    }
};

class Solution
{
public:
    int dp[100][100];
    int totalcost(vector<vector<int>> &costs, int n, int a, int b)
    {
        if (a == 0 && b == 0 && n == 0)
            return 0;
        if (a < 0 || b < 0)
            return 100000;
        if (dp[a][b] != -1)
            return dp[a][b];
        else
            return dp[a][b] = min(costs[n - 1][0] + totalcost(costs, n - 1, a - 1, b),
                                  costs[n - 1][1] + totalcost(costs, n - 1, a, b - 1));
    }

    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        memset(dp, -1, sizeof(dp));
        return totalcost(costs, n, n / 2, n / 2);
    }
};