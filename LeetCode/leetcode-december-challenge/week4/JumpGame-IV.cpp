#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
        {
            return 0;
        }
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        visited[0] = true;
        q.push(0);
        int dist = 0;
        int layerSz = 1;

        while (!q.empty())
        {
            if (layerSz == 0)
            {
                layerSz = q.size();
                dist++;
            }
            int curr = q.front();
            q.pop();
            //cout<<"POPPING: "<<curr<<endl;
            if (curr == (n - 1))
            {
                return dist;
            }
            for (int v : m[arr[curr]])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                    //cout<<"PUSHING: "<<v<<endl;
                }
            }
            m[arr[curr]].clear();
            if (curr + 1 < n && !visited[curr + 1])
            {
                visited[curr + 1] = true;
                q.push(curr + 1);

                //cout<<"PUSHING: "<<curr+1<<endl;
            }
            if (curr - 1 >= 0 && !visited[curr - 1])
            {
                visited[curr - 1] = true;
                q.push(curr - 1);
                //cout<<"PUSHING: "<<curr-1<<endl;
            }
            layerSz--;
        }
        return -1;
    }
};