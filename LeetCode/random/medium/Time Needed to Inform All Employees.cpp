#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalTime = 0;

    void dfs(vector<vector<int>> &adjList, vector<int> &informTime, int curr, int currTime)
    {
        currTime += informTime[curr];
        totalTime = max(totalTime, currTime);
        for (int v : adjList[curr])
        {
            dfs(adjList, informTime, v, currTime);
        }
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        vector<vector<int>> adjList(n, vector<int>());
        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                adjList[manager[i]].push_back(i);
            }
        }

        dfs(adjList, informTime, headID, 0);
        return totalTime;
    }
};