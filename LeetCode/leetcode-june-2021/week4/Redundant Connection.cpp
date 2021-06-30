#include <bits/stdc++.h>
using namespace std;

//Union Find
class Solution
{
public:
    int find(int v, vector<int> &parent)
    {
        if (parent[v] == -1)
        {
            return v;
        }
        return parent[v] = find(parent[v], parent);
    }

    void union_op(int from, int to, vector<int> &parent, vector<int> &rank)
    {
        if (rank[from] > rank[to])
        {
            parent[to] = from;
        }
        else if (rank[from] < rank[to])
        {
            parent[from] = to;
        }
        else
        {
            parent[from] = to;
            rank[to]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1, -1);
        vector<int> rank(n + 1, 0);

        vector<int> result;
        for (int i = 0; i < n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            int ans1 = find(u, parent);
            int ans2 = find(v, parent);

            if (ans1 == ans2)
            {
                result = {u, v};
            }
            else
            {
                union_op(ans1, ans2, parent, rank);
            }
        }

        return result;
    }
};