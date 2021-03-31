#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size();
        int bulls = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                guess[i] = 'a';
                bulls++;
            }
            else
            {
                mp[secret[i]]++;
            }
        }
        int cows = 0;
        for (int i = 0; i < n; i++)
        {
            if (guess[i] == 'a')
            {
                continue;
            }
            else
            {
                if (mp[guess[i]] != 0)
                {
                    cows++;
                    mp[guess[i]]--;
                }
            }
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};