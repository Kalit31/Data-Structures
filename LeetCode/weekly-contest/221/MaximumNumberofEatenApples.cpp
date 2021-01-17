#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        int ans = 0;
        int n = apples.size();
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
        for (int i = 0; i < n || !q.empty(); i++)
        {
            if (i < n && apples[i] != 0)
            {
                q.push({i + days[i], apples[i]});
            }
            while (!q.empty() && q.top()[0] <= i)
            {
                q.pop();
            }
            if (!q.empty())
            {
                array<int, 2> curr = q.top();
                q.pop();
                ans++;
                curr[1]--;
                if (curr[1] > 0)
                    q.push({curr[0], curr[1]});
            }
        }
        return ans;
    }
};