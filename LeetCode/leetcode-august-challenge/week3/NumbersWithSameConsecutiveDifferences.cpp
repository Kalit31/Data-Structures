#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void build(vector<int> &result, int t, int n, int k)
    {
        if (n == 0)
        {
            result.push_back(t);
            return;
        }
        int last = t % 10;
        for (int i = 0; i <= 9; i++)
        {
            if (abs(i - last) == k)
            {
                build(result, t * 10 + i, n - 1, k);
            }
        }
    }

    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> result;
        int t;
        if (N == 1)
        {
            result.push_back(0);
        }
        for (int i = 1; i <= 9; i++)
        {
            build(result, i, N - 1, K);
        }
        return result;
    }
};