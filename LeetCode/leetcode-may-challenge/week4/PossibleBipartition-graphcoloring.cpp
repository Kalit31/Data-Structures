#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adjList(N + 1);

        for (int i = 0; i < dislikes.size(); i++)
        {
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> color(N + 1, -1);
        for (int i = 1; i <= N; i++)
        {
            if (color[i] == -1)
            {
                if (!isBipartite(adjList, i, color))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &adjList, int node, vector<int> &color)
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