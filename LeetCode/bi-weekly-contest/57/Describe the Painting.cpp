#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    vector<vector<long long>> splitPainting(vector<vector<int>> &segments)
    {
        vector<vector<ll>> result;
        int n = segments.size();
        const int N = 2e5 + 25;

        vector<ll> pref(N, 0);

        for (int i = 0; i < n; i++)
        {
            pref[segments[i][0] * 2] += segments[i][2];
            pref[segments[i][1] * 2 - 1] -= segments[i][2];
        }
        for (int i = 1; i < N; i++)
        {
            pref[i] += pref[i - 1];
        }

        int i = 0;
        while (i < N)
        {
            while (i < N && pref[i] == 0)
            {
                i++;
            }
            if (i == N)
            {
                break;
            }
            ll currColor = pref[i];
            int start = i;
            while (i < N && pref[i] == currColor)
            {
                i++;
            }
            int x = (start + 1) / 2;
            int y = (i + 1) / 2;
            if (x == y)
            {
                continue;
            }
            result.push_back({x, y, currColor});
        }
        return result;
    }
};