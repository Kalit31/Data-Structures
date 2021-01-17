#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;

    int countPairs(vector<int> &deliciousness)
    {
        vector<ll> powerOfTwo(23, 0);
        ll curr = 1;
        for (int i = 1; i <= 22; i++)
        {
            powerOfTwo[i] = curr;
            curr *= (ll)2;
        }
        ll num = 0;
        int n = deliciousness.size();
        unordered_map<ll, ll> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= 22; j++)
            {
                int toFind = powerOfTwo[j] - deliciousness[i];
                if (toFind < 0)
                {
                    continue;
                }
                else
                {
                    if (m.find(toFind) != m.end())
                    {
                        num = (num + m[toFind]) % mod;
                    }
                }
            }
            m[deliciousness[i]]++;
        }
        return num;
    }
};