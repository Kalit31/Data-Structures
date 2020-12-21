#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectcycle(vector<vector<int>> &adjList, vector<int> &visited, int v)
    {
        if (visited[v] == 1)
        {
            return true;
        }
        if (visited[v] == 2)
        {
            return false;
        }
        visited[v] = 1;
        for (int n : adjList[v])
        {
            if (detectcycle(adjList, visited, n))
            {
                return true;
            }
        }
        visited[v] = 2;
        return false;
    }

    bool detectCycle(vector<vector<int>> &adjList, int n)
    {
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (detectcycle(adjList, visited, i))
                {
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(vector<vector<int>> &adjList, int ind, vector<bool> &visited, stack<int> &st)
    {
        visited[ind] = true;
        for (int n : adjList[ind])
        {
            if (!visited[n])
            {
                dfs(adjList, n, visited, st);
            }
        }
        st.push(ind);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; i++)
        {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> res;
        if (detectCycle(adjList, numCourses))
        {
            return res;
        }
        stack<int> st;
        vector<bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                dfs(adjList, i, visited, st);
            }
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};