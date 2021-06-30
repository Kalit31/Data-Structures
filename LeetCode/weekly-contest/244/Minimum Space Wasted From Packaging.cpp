#include <bits/stdc++.h>
using namespace std;

#define ll long long int
class Solution
{
public:
    int minWastedSpace(vector<int> &packages, vector<vector<int>> &boxes)
    {
        const int mod = 1e9 + 7;
        int n = packages.size();
        int m = boxes.size();

        sort(packages.begin(), packages.end());

        vector<ll> pref(n);
        pref[0] = packages[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + packages[i];
        }

        ll ans = LONG_LONG_MAX;
        for (int i = 0; i < m; i++)
        {
            sort(boxes[i].begin(), boxes[i].end());
            if (boxes[i].back() < packages[n - 1])
                continue;
            int lastPos = 0;
            ll currAns = 0;
            int j = 0;
            while (j < boxes[i].size() && boxes[i][j] < packages[0])
            {
                j++;
            }
            for (; j < boxes[i].size(); j++)
            {
                int pos = upper_bound(packages.begin(), packages.end(), boxes[i][j]) - packages.begin() - 1;
                ll sum = pref[pos] - (lastPos > 0 ? pref[lastPos - 1] : 0);
                ll cnt = pos - lastPos + 1;
                currAns += (boxes[i][j] * cnt) - sum;
                lastPos = pos + 1;
            }
            ans = min(ans, currAns);
        }

        if (ans == LONG_LONG_MAX)
        {
            return -1;
        }
        return ans % mod;
    }
};