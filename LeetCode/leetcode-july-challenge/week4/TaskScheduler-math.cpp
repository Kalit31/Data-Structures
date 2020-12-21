#include <bits/stdc++.h>
using namespace std;

// Didn't get this one
//    |
//    V
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int leastInterval(vector<char> &tasks, int n)
    {
        if (tasks.empty())
            return 0;
        if (n == 0)
            return tasks.size();

        int size = tasks.size();

        vector<int> count(26);
        int maxm = 0;
        for (char c : tasks)
        {
            count[c - 'A']++;
            maxm = max(maxm, count[c - 'A']);
        }

        int total = 0, required = n * (maxm - 1);
        for (auto it : count)
        {
            total += min(it, maxm - 1);
        }

        total -= (maxm - 1);
        if (total >= required)
        {
            return size;
        }

        return required - total + size;
    }
};

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
        {
            return tasks.size();
        }
        int freq[26] = {0};
        int maxCnt = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
            maxCnt = max(maxCnt, freq[tasks[i] - 'A']);
        }

        int res = (maxCnt - 1) * (n + 1);
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == maxCnt)
            {
                res++;
            }
        }
        res = max((int)tasks.size(), res);
        return res;
    }
};

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        if (n == 0)
        {
            return tasks.size();
        }
        int freq[26] = {0};
        for (int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
        }
        priority_queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                q.push(freq[i]);
            }
        }
        int time = 0;
        while (!q.empty())
        {
            vector<int> t;
            for (int i = 0; i <= n; i++)
            {
                if (!q.empty())
                {
                    t.push_back(q.top());
                    q.pop();
                }
            }
            for (int i : t)
            {
                if (--i > 0)
                {
                    q.push(i);
                }
            }
            time += q.empty() ? t.size() : (n + 1);
        }
        return time;
    }
};