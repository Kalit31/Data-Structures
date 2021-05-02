#include <bits/stdc++.h>
using namespace std;

//Tarjan's algorithm

class Solution
{
public:
    void dfs(vector<vector<int>> &adjList, int currNode, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int>> &bridges)
    {
        static int time = 0;
        disc[currNode] = time;
        low[currNode] = time;
        time++;

        for (int v : adjList[currNode])
        {
            if (disc[v] == -1)
            {
                parent[v] = currNode;
                dfs(adjList, v, disc, low, parent, bridges);
                low[currNode] = min(low[currNode], low[v]);
                if (low[v] > disc[currNode])
                {
                    bridges.push_back({currNode, v});
                }
            }
            else if (v != parent[currNode])
            {
                low[currNode] = min(low[currNode], disc[v]);
            }
        }
    }

    void tarjans(vector<vector<int>> &adjList, int n, vector<vector<int>> &bridges)
    {
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (disc[i] == -1)
                dfs(adjList, i, disc, low, parent, bridges);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adjList(n, vector<int>());

        for (int i = 0; i < connections.size(); i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }

        vector<vector<int>> bridges;

        tarjans(adjList, n, bridges);

        return bridges;
    }
};