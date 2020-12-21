#include <bits/stdc++.h>
using namespace std;

// Time limit exceeded
class Solution
{
public:
    int dfs(unordered_map<int, vector<int>> &edges, int root, unordered_map<int, bool> &visited)
    {
        int size = 1;
        visited[root] = true;
        for (int v : edges[root])
        {
            if (!visited[v])
            {
                size += dfs(edges, v, visited);
            }
        }
        return size;
    }

    int largestComponentSize(vector<int> &A)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        unordered_map<int, vector<int>> edges;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                if (__gcd(A[i], A[j]) != 1)
                {
                    edges[A[i]].push_back(A[j]);
                    edges[A[j]].push_back(A[i]);
                }
            }
        }
        unordered_map<int, bool> visited;
        int maxSize = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (!visited[A[i]])
            {
                maxSize = max(maxSize, dfs(edges, A[i], visited));
            }
        }
        return maxSize;
    }
};

// Disjoint Set Union

class Solution
{
public:
    vector<int> parent;
    vector<int> rank;

    int getParent(int x)
    {
        if (parent[x] == -1)
            return x;
        return parent[x] = getParent(parent[x]);
    }

    void union_op(int x, int y)
    {
        int parX = getParent(x);
        int parY = getParent(y);
        if (parX == parY)
            return;
        if (rank[parX] >= rank[parY])
        {
            rank[parX] += rank[parY];
            parent[parY] = parX;
        }
        else
        {
            rank[parY] += rank[parX];
            parent[parX] = parY;
        }
    }

    int largestComponentSize(vector<int> &A)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int n = A.size();
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);

        unordered_map<int, int> m;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            int x = A[i];
            for (int j = 2; j * j <= x; j++)
            {
                if (x % j == 0)
                {
                    if (m.count(j))
                    {
                        union_op(m[j], i);
                    }
                    else
                    {
                        m[j] = i;
                    }
                    if (m.count(x / j))
                    {
                        union_op(m[x / j], i);
                    }
                    else
                    {
                        m[x / j] = i;
                    }
                }
            }
            if (m.count(x))
            {
                union_op(m[x], i);
            }
            else
            {
                m[x] = i;
            }
            maxLen = max(maxLen, rank[getParent(i)]);
        }
        return maxLen;
    }
};