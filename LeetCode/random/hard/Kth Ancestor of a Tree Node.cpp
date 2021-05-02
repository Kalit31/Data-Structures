#include <bits/stdc++.h>
using namespace std;

class TreeAncestor
{
public:
    vector<vector<int>> ancestor;
    vector<int> depth;
    int h = 0;

    TreeAncestor(int n, vector<int> &parent)
    {
        h = 0;
        while ((1 << h) <= n)
        {
            h++;
        }
        ancestor.clear();
        ancestor.resize(n, vector<int>(h));
        depth.clear();
        depth.resize(n, 0);
        parent[0] = 0;
        for (int i = 0; i < n; i++)
        {
            ancestor[i][0] = parent[i];
            if (i != 0)
            {
                depth[i] = depth[parent[i]] + 1;
            }
            for (int j = 1; j < h; j++)
            {
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        if (depth[node] < k)
        {
            return -1;
        }
        for (int i = 0; i < h; i++)
        {
            if (k & (1 << i))
            {
                node = ancestor[node][i];
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */