#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        ll ans = 0;
        vector<ll> freq(26, 0);
        vector<ll> freq2(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        int n = s.size();
        map<ll, bool> mp;

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']--;
            for (int j = 0; j < 26; j++)
            {
                if ((freq[j] * freq2[j]) >= 1)
                {
                    ll hash = (26 * 26 * j) + (26 * (s[i] - 'a')) + j;
                    if (mp[hash])
                    {
                        continue;
                    }
                    mp[hash] = true;
                    ans++;
                }
            }
            freq2[s[i] - 'a']++;
        }

        return ans;
    }
};