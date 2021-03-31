#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = 1;
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && mp.find(arr[i] / arr[j]) != mp.end())
                {
                    ll k = arr[i] / arr[j];
                    ll toAdd = mp[k] * mp[arr[j]];
                    mp[arr[i]] = (mp[arr[i]] + toAdd) % mod;
                }
            }
        }

        ll ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans = (ans + it->second) % mod;
        }
        return ans;
    }
};