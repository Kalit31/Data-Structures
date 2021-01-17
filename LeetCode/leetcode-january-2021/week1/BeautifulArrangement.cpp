#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cnt = 0;
    void build(vector<int> &taken, int curr)
    {
        int n = taken.size();
        n--;
        if (curr == n + 1)
        {
            cnt++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (!taken[i])
            {
                if (curr % i == 0 || i % curr == 0)
                {
                    taken[i] = true;
                    build(taken, curr + 1);
                    taken[i] = false;
                }
            }
        }
    }

    int countArrangement(int n)
    {
        cnt = 0;
        vector<int> taken(n + 1, false);
        build(taken, 1);
        return cnt;
    }
};