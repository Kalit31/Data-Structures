#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> adjList(numCourses,vector<int>());
        vector<int> indegree(numCourses,0);
        int n = prerequisites.size();
        
        for(int i=0;i<n;i++){
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int coursesCompleted = 0;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            coursesCompleted++;
            for(int v:adjList[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(coursesCompleted != numCourses){
            return vector<int>();
        }        
        return result;
    }
};

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
