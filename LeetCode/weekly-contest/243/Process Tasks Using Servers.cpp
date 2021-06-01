#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct mycomp
    {
        bool operator()(const array<int, 3> &a, const array<int, 3> &b)
        {
            if (a[1] == b[1])
            {
                return a[2] > b[2];
            }
            return a[1] > b[1];
        }
    };

    struct mycomp2
    {
        bool operator()(const array<int, 3> &a, const array<int, 3> &b)
        {
            if (a[0] == b[0])
            {
                if (a[1] == b[1])
                {
                    return a[2] > b[2];
                }
                return a[1] > b[1];
            }
            return a[0] > b[0];
        }
    };

    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        int n = servers.size();
        int m = tasks.size();

        vector<int> result(m);

        priority_queue<array<int, 3>, vector<array<int, 3>>, mycomp> pq;
        priority_queue<array<int, 3>, vector<array<int, 3>>, mycomp2> tpq;

        for (int i = 0; i < n; i++)
        {
            pq.push({0, servers[i], i});
        }

        for (int i = 0; i < m; i++)
        {
            int currTask = tasks[i];
            while (!tpq.empty() && (tpq.top())[0] <= i)
            {
                pq.push({tpq.top()});
                tpq.pop();
            }
            if (pq.empty())
            {
                auto curr = tpq.top();
                tpq.pop();
                result[i] = curr[2];
                curr[0] += currTask;
                tpq.push(curr);
            }
            else
            {
                auto curr = pq.top();
                pq.pop();
                result[i] = curr[2];
                curr[0] = i + currTask;
                tpq.push(curr);
            }
        }
        return result;
    }
};