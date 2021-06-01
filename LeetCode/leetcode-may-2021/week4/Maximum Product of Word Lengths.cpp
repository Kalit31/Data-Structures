#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool shareLetters(string &a, string &b)
    {
        vector<int> freq(26, 0);
        for (char ch : a)
        {
            freq[ch - 'a']++;
        }
        for (char ch : b)
        {
            if (freq[ch - 'a'] != 0)
            {
                return false;
            }
        }
        return true;
    }

    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (shareLetters(words[i], words[j]))
                {
                    ans = max(ans, (int)(words[i].size()) * (int)(words[j].size()));
                }
            }
        }

        return ans;
    }
};

class Solution
{
public:
    bool shareLetters(bitset<26> &a, bitset<26> &b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] && b[i])
            {
                return false;
            }
        }
        return true;
    }

    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        int ans = 0;

        vector<bitset<26>> charPresent(n);

        for (int i = 0; i < n; i++)
        {
            for (char ch : words[i])
            {
                charPresent[i][ch - 'a'] = 1;
            }
            for (int j = 0; j < i; j++)
            {
                if (shareLetters(charPresent[i], charPresent[j]))
                {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }
};