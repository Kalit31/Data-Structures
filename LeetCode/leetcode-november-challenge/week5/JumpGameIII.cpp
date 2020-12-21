#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        unordered_map<int, bool> seen;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (arr[curr] == 0)
            {
                return true;
            }
            if (seen.find(curr) != seen.end())
            {
                continue;
            }
            seen[curr] = true;
            if (curr - arr[curr] >= 0)
            {
                q.push(curr - arr[curr]);
            }
            if (curr + arr[curr] < n)
            {
                q.push(curr + arr[curr]);
            }
        }
        return false;
    }
};