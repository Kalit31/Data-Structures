#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        int m = edges.size();
        vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < m; i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        vector<vector<int>> colorCnt(n, vector<int>(26, 0));
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                colorCnt[i][colors[i] - 'a']++;
            }
        }

        int nodeCnt = 0;
        int ans = 0;

        while (q.size())
        {
            int currNode = q.front();
            q.pop();
            int currMax = *max_element(colorCnt[currNode].begin(), colorCnt[currNode].end());
            ans = max(ans, currMax);
            nodeCnt++;
            for (int v : adjList[currNode])
            {
                for (int color = 0; color < 26; color++)
                {
                    colorCnt[v][color] = max(colorCnt[v][color], colorCnt[currNode][color] + (color == (colors[v] - 'a')));
                }
                indegree[v]--;
                if (indegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return nodeCnt == n ? ans : -1;
    }
};