#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    int mod = 1e9 + 7;

    int dfs(vector<vector<array<ll, 2>>> &adjList, int node, vector<ll> &dp, vector<ll> &dist)
    {
        if (node == 0)
        {
            return 1;
        }
        if (dp[node] != -1)
        {
            return dp[node];
        }
        int ways = 0;
        for (array<ll, 2> &v : adjList[node])
        {
            int wt1 = dist[node];
            int wt2 = dist[v[1]];
            if (wt2 > wt1)
            {
                ways = (ways + dfs(adjList, v[1], dp, dist)) % mod;
            }
        }
        dp[node] = ways % mod;
        return dp[node];
    }

    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        vector<vector<array<ll, 2>>> adjList(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            u--;
            v--;
            adjList[u].push_back({edges[i][2], v});
            adjList[v].push_back({edges[i][2], u});
        }
        priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
        vector<ll> dist(n, INT_MAX);
        dist[n - 1] = 0;
        q.push({0, n - 1});
        set<int> processed;
        while (!q.empty())
        {
            array<ll, 2> curr = q.top();
            q.pop();

            if (processed.find(curr[1]) != processed.end())
            {
                continue;
            }
            for (array<ll, 2> v : adjList[curr[1]])
            {
                if (dist[v[1]] > dist[curr[1]] + v[0])
                {
                    dist[v[1]] = dist[curr[1]] + v[0];
                    q.push({dist[v[1]], v[1]});
                }
            }
            processed.insert(curr[1]);
        }

        //         for(int i=0;i<n;i++){
        //             cout<<dist[i]<<" ";
        //         }

        vector<ll> dp(n, -1);
        return dfs(adjList, n - 1, dp, dist);
    }
};