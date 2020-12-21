#include <bits/stdc++.h>
using namespace std;

//Most Efficient based on topological sort
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<int> adj[n];
        int in[n];
        int vis[n];
        for (int i = 0; i < n; i++)
        {
            in[i] = 0;
            vis[i] = 0;
        }
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            in[e[0]]++;
            in[e[1]]++;
        }
        if (n == 3)
        {
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (in[i] == 1)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        int temp = n;
        while (temp > 2)
        {
            int sz = q.size();
            while (sz--)
            {
                int x = q.front();
                temp--;
                q.pop();
                for (int i = 0; i < adj[x].size(); i++)
                {
                    if (!vis[adj[x][i]])
                    {
                        in[adj[x][i]]--;
                        if (in[adj[x][i]] == 1)
                        {
                            q.push(adj[x][i]);
                            vis[adj[x][i]] = 1;
                        }
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

//Based on topological sorting
class Solution
{
public:
    // A graph can have atmost 2 MHT's
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, unordered_set<int>> adjList;

        if (n == 1)
        {
            return {0};
        }

        if (n == 2)
        {
            return {0, 1};
        }

        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].insert(edges[i][1]);
            adjList[edges[i][1]].insert(edges[i][0]);
        }

        vector<int> leaves;
        for (int i = 0; i < n; i++)
        {
            if (adjList[i].size() == 1)
            {
                leaves.push_back(i);
            }
        }

        int remainingNodes = n;
        while (remainingNodes > 2)
        {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;

            for (int leaf : leaves)
            {
                for (int v : adjList[leaf])
                {
                    adjList[v].erase(leaf);
                    if (adjList[v].size() == 1)
                    {
                        newLeaves.push_back(v);
                    }
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

// There are some issues in this solution
class Solution
{
public:
    // A graph can have atmost 2 MHT's
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n, vector<int>());

        if (n == 2)
        {
            return {0, 1};
        }

        for (int i = 0; i < edges.size(); i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int v : adjList[curr])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[curr] + 1;
                    q.push(v);
                }
            }
        }
        int farthestNode = 0;
        int maxDist = 0;
        for (int i = 1; i < n; i++)
        {
            if (dist[i] > maxDist)
            {
                farthestNode = i;
                maxDist = dist[i];
            }
        }
        dist.clear();
        dist.resize(n, -1);
        dist[farthestNode] = 0;
        //cout<<"FARTHEST NODE: "<<farthestNode<<endl;
        q.push(farthestNode);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int v : adjList[curr])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[curr] + 1;
                    q.push(v);
                }
            }
        }
        maxDist = 0;
        for (int i = 1; i < n; i++)
        {
            if (dist[i] > maxDist)
            {
                maxDist = dist[i];
            }
        }
        vector<int> result;
        //cout<<"MAX: "<<maxDist<<endl;
        if (maxDist % 2 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (dist[i] == (maxDist / 2))
                {
                    result.push_back(i);
                }
            }
            if (result.size() == 1)
            {
                return result;
            }
            int root = result[0];
            //cout<<"ROOT: "<<root<<endl;
            for (int i = 0; i < result.size(); i++)
            {
                if (adjList[result[i]].size() > adjList[root].size())
                {
                    root = result[i];
                    //cout<<"ROOT: "<<root<<endl;
                }
            }
            return {root};
        }
        else
        {
            int a = maxDist / 2;
            int b = a + 1;
            for (int i = 0; i < n; i++)
            {
                if (dist[i] == a)
                {
                    result.push_back(i);
                }
            }
            int root = result[0];
            //cout<<"ROOT: "<<root<<endl;
            for (int i = 0; i < result.size(); i++)
            {
                if (adjList[result[i]].size() > adjList[root].size())
                {
                    root = result[i];
                    //cout<<"ROOT: "<<root<<endl;
                }
            }
            for (int v : adjList[root])
            {
                if (dist[v] == b)
                {
                    return {root, v};
                }
            }
            return {};
        }
        return result;
    }
};