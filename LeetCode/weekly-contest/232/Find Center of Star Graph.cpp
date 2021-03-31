#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n - 1; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            u--;
            v--;
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }
        for (int i = 0; i < n; i++)
        {
            if (adjList[i].size() == n - 1)
            {
                return i + 1;
            }
        }
        return -1;
    }
};