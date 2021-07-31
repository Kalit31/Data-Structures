#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &result, vector<int> &currPath, int curr)
    {
        int n = graph.size();
        currPath.push_back(curr);
        if (curr == n - 1)
        {
            result.push_back(currPath);
            currPath.pop_back();
            return;
        }
        for (int v : graph[curr])
        {
            dfs(graph, result, currPath, v);
        }
        currPath.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> result;
        vector<int> currPath;

        dfs(graph, result, currPath, 0);
        return result;
    }
};