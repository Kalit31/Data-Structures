#include <bits/stdc++.h>
using namespace std;

// DFS with check for visited nodes and a check for cost
class Solution
{
public:
    int minCost = INT_MAX;

    void dfs(vector<vector<int>> &cost, int currPos, int dst, int stopsRemaining, int currCost, vector<bool> &visited)
    {
        if (currPos == dst)
        {
            if (currCost < minCost)
            {
                minCost = currCost;
            }
            return;
        }
        if (stopsRemaining < 0)
        {
            return;
        }
        visited[currPos] = true;
        for (int i = 0; i < cost.size(); i++)
        {
            if (cost[currPos][i] != -1 && currCost + cost[currPos][i] <= minCost)
            {
                dfs(cost, i, dst, stopsRemaining - 1, currCost + cost[currPos][i], visited);
            }
        }
        visited[currPos] = false;
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<int>> cost(n, vector<int>(n, -1));

        for (int i = 0; i < flights.size(); i++)
        {
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }

        vector<bool> visited(n, false);

        dfs(cost, src, dst, K, 0, visited);

        if (minCost == INT_MAX)
        {
            return -1;
        }
        return minCost;
    }
};

// Simple DFS
class Solution
{
public:
    int minCost = INT_MAX;

    void dfs(vector<vector<int>> &cost, int currPos, int dst, int stopsRemaining, int currCost)
    {
        if (currPos == dst)
        {
            if (currCost < minCost)
            {
                minCost = currCost;
            }
            return;
        }
        if (stopsRemaining < 0)
        {
            return;
        }
        for (int i = 0; i < cost.size(); i++)
        {
            if (cost[currPos][i] != -1)
            {
                dfs(cost, i, dst, stopsRemaining - 1, currCost + cost[currPos][i]);
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        vector<vector<int>> cost(n, vector<int>(n, -1));

        for (int i = 0; i < flights.size(); i++)
        {
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }

        dfs(cost, src, dst, K, 0);

        if (minCost == INT_MAX)
        {
            return -1;
        }
        return minCost;
    }
};