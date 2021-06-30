#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        vector<vector<int>> index(26, vector<int>());

        for (int i = 0; i < s.size(); i++)
        {
            index[s[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < words.size(); i++)
        {
            bool poss = true;
            int startInd = -1;
            for (char ch : words[i])
            {
                auto it = upper_bound(index[ch - 'a'].begin(), index[ch - 'a'].end(), startInd);
                if (it == index[ch - 'a'].end())
                {
                    poss = false;
                    break;
                }
                else
                {
                    startInd = *it;
                }
            }
            if (poss)
            {
                ans++;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int ans = 0;
        int n = s.size();
        map<string, int> mp;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];

            if (mp.find(word) != mp.end())
            {
                ans += mp[word];
                continue;
            }

            int m = word.size();

            int j = 0;
            int k = 0;

            while (j < m && k < n)
            {
                if (word[j] == s[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    k++;
                }
            }
            ans += (mp[word] = j == m);
        }

        return ans;
    }
};