#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int minMoves(vector<int> &nums, int k)
    {
        ll n = nums.size();
        vector<ll> idx;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                idx.push_back(i);
                // cout<<"PUSHING: "<<i<<endl;
            }
        }
        ll m = idx.size();
        vector<ll> pref(m + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            pref[i] = pref[i - 1] + idx[i - 1];
            //cout<<"PREF: "<<pref[i]<<endl;
        }
        ll ans = LONG_LONG_MAX;
        if (k % 2 == 1)
        {
            ll radius = (k - 1) / 2;
            // cout<<radius<<endl;
            for (int i = radius; i < m - radius; i++)
            {
                //cout<<"I:"<<i<<endl;
                ll r = pref[i + radius + 1] - pref[i + 1];
                //cout<<"R: "<<r<<endl;
                ll l = pref[i] - pref[i - radius];
                //cout<<"L: "<<l<<endl;
                ans = min(ans, r - l);
            }
            return ans - radius * (radius + 1);
        }
        else
        {
            ll radius = (k - 1) / 2;
            //cout<<radius<<endl;
            for (int i = radius; i < m - radius - 1; i++)
            {
                ll r = pref[i + radius + 2] - pref[i + 1];
                ll l = pref[i] - pref[i - radius];
                ans = min(ans, r - l - idx[i]);
            }
            return ans - (radius + 1) * (radius + 1);
        }
    }
};