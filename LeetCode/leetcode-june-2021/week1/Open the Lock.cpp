#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        map<string, bool> visited;
        queue<string> q;

        for (string s : deadends)
        {
            visited[s] = true;
        }

        string start = "0000";

        if (visited[start])
        {
            return -1;
        }

        q.push(start);
        visited[start] = true;
        int lvl = 0;
        int sz = q.size();

        while (!q.empty())
        {
            while (sz)
            {
                string curr = q.front();
                q.pop();
                if (curr == target)
                {
                    return lvl;
                }
                for (int i = 0; i < 4; i++)
                {
                    string nxt = curr;
                    if (curr[i] != '9')
                    {
                        nxt[i] = nxt[i] + 1;
                    }
                    else
                    {
                        nxt[i] = '0';
                    }
                    if (!visited[nxt])
                    {
                        visited[nxt] = true;
                        q.push(nxt);
                    }
                    nxt = curr;
                    if (curr[i] != '0')
                    {
                        nxt[i] = nxt[i] - 1;
                    }
                    else
                    {
                        nxt[i] = '9';
                    }
                    if (!visited[nxt])
                    {
                        visited[nxt] = true;
                        q.push(nxt);
                    }
                }

                sz--;
            }
            sz = q.size();
            lvl++;
        }
        return -1;
    }
};