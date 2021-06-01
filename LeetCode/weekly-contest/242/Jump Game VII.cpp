#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();

        queue<int> q;
        vector<bool> visited(n, false);
        visited[0] = true;
        q.push(0);
        int lastEnd = 0;

        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            if (i == n - 1)
            {
                return true;
            }
            //s[i] is a '0'
            for (int j = max(lastEnd, i + minJump); j <= min(n - 1, i + maxJump); j++)
            {
                if (s[j] == '0' && !visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
            lastEnd = max(lastEnd, i + maxJump);
        }
        return false;
    }
};

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.size();
        int cnt = 0;
        vector<bool> reachable(n, false);
        reachable[0] = true;

        //a cell at ith index is reachable if a cell in [i-maxJump,i-minJump] is reachable.
        for (int i = 1; i < n; i++)
        {
            if (i - minJump >= 0)
            {
                cnt += reachable[i - minJump];
            }
            if (i - maxJump > 0)
            {
                cnt -= reachable[i - maxJump - 1];
            }
            reachable[i] = s[i] == '0' && cnt > 0;
        }
        return reachable[n - 1];
    }
};