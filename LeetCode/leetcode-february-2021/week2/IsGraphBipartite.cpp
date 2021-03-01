#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adjList(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                adjList[i].push_back(graph[i][j]);
            }
        }

        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!find(adjList, i, color))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool find(vector<vector<int>> &adjList, int node, vector<int> &color)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int e : adjList[curr])
            {
                if (color[e] == color[curr])
                {
                    return false;
                }
                if (color[e] == -1)
                {
                    color[e] = 1 - color[curr];
                    q.push(e);
                }
            }
        }
        return true;
    }
};