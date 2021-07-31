#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;

    vector<int> getPattern(int choice, int m)
    {
        int div = pow(3, m - 1);
        vector<int> colors;
        for (int i = 0; i < m; i++)
        {
            int curr = choice / div;
            colors.push_back(curr);
            choice -= curr * div;
            div /= 3;
        }
        return colors;
    }

    bool isChoiceValid(vector<int> &colors)
    {
        for (int i = 0; i < colors.size() - 1; i++)
        {
            if (colors[i] == colors[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    ll build(int n, int choice, vector<vector<int>> &dp, map<int, vector<int>> &mp)
    {
        if (n == 0)
        {
            return 1;
        }
        if (dp[n][choice] != -1)
        {
            return dp[n][choice];
        }
        ll ans = 0;
        for (int newch : mp[choice])
        {
            ans = (ans + build(n - 1, newch, dp, mp)) % mod;
        }
        return dp[n][choice] = ans;
    }

    int colorTheGrid(int m, int n)
    {
        int choices = pow(3, m);
        vector<vector<int>> dp(n + 1, vector<int>(choices + 1, -1));

        vector<int> validChoices;
        for (int choice = 0; choice < choices; choice++)
        {
            vector<int> patt = getPattern(choice, m);
            if (isChoiceValid(patt))
            {
                validChoices.push_back(choice);
            }
        }

        map<int, vector<int>> mp;

        for (int choice1 : validChoices)
        {
            vector<int> patt1 = getPattern(choice1, m);
            for (int choice2 : validChoices)
            {
                vector<int> patt2 = getPattern(choice2, m);
                bool poss = true;
                for (int i = 0; i < m; i++)
                {
                    if (patt1[i] == patt2[i])
                    {
                        poss = false;
                        break;
                    }
                }
                if (poss)
                {
                    mp[choice1].push_back(choice2);
                }
            }
        }

        ll ans = 0;
        for (int choice : validChoices)
        {
            ans = (ans + build(n - 1, choice, dp, mp)) % mod;
        }
        return ans;
    }
};