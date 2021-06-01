#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

//Method1: Using stack and recursion
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

vector<int> findOrder(int numCourses, vector<vector<int>> &adjList)
{
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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>());
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
    }
    vector<int> schedule = findOrder(n, adjList);
}

//Method 2: Iterative using indegrees of each node
void solve2()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjList(n, vector<int>());
    int a, b;
    vector<int> indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adjList[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> result;
    int nodesVisited = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        nodesVisited++;
        for (int v : adjList[curr])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    if (nodesVisited != n)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for (int x : result)
    {
        cout << x + 1 << " ";
    }
    cout << endl;
}
