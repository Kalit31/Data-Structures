#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &adjList, int currNode, int parent, vector<int> &result, vector<int> &subtreeSize)
    {
        for (int v : adjList[currNode])
        {
            if (v != parent)
            {
                dfs(adjList, v, currNode, result, subtreeSize);
                subtreeSize[currNode] += subtreeSize[v];
                result[currNode] += result[v] + subtreeSize[v];
            }
        }
    }

    void dfs2(vector<vector<int>> &adjList, int currNode, int parent, vector<int> &result, vector<int> &subtreeSize)
    {
        for (int v : adjList[currNode])
        {
            if (v != parent)
            {
                result[v] = result[currNode] - subtreeSize[v] + (adjList.size() - subtreeSize[v]);
                dfs2(adjList, v, currNode, result, subtreeSize);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(N, vector<int>());

        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> result(N, 0);
        vector<int> subtreeSize(N, 1);

        dfs(adjList, 0, -1, result, subtreeSize);
        dfs2(adjList, 0, -1, result, subtreeSize);

        return result;
    }
};