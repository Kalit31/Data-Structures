#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;
    int threeSumMulti(vector<int> &arr, int target)
    {
        ll ans = 0;
        vector<int> cnt(101, 0);
        for (int x : arr)
        {
            cnt[x]++;
        }
        for (int i = 0; i <= target; i++)
        {
            for (int j = i; j <= target - i; j++)
            {
                int k = target - i - j;
                if (i > 100 || j > 100 || k > 100 || k < 0)
                    continue;
                if (k < j)
                    continue;
                if (i != j && j != k && k != i)
                {
                    ans = (ans + (((cnt[i] * cnt[j]) % mod) * cnt[k]) % mod) % mod;
                }
                else if (i == j && j == k)
                {
                    ll t = cnt[i];
                    ans = (ans + (t * (t - 1) * (t - 2)) / 6) % mod;
                }
                else if (i == j || j == k)
                {
                    if (i == j)
                    {
                        ll t1 = cnt[i];
                        ll t2 = cnt[k];
                        ans = (ans + ((t1 * (t1 - 1)) / 2) * t2) % mod;
                    }
                    else
                    {
                        ll t2 = cnt[i];
                        ll t1 = cnt[j];
                        ans = (ans + ((t1 * (t1 - 1)) / 2) * t2) % mod;
                    }
                }
            }
        }
        return ans;
    }
};