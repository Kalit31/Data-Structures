#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int balancedString(string s)
    {
        int n = s.size();
        int ans = n;
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }

        int req = n / 4;

        if (mp['Q'] == req && mp['W'] == req && mp['E'] == req && mp['R'] == req)
        {
            return 0;
        }

        vector<char> chars = {'Q', 'W', 'E', 'R'};

        for (char ch : chars)
        {
            mp[ch] = max(0, mp[ch] - req);
        }

        int i = 0;
        for (int j = 0; j < n; j++)
        {
            mp[s[j]]--;
            while (i <= j && mp['Q'] <= 0 && mp['W'] <= 0 && mp['E'] <= 0 && mp['R'] <= 0)
            {
                ans = min(ans, j - i + 1);
                mp[s[i]]++;
                i++;
            }
        }
        return ans;
    }
};