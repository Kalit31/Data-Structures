#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            map<char, char> mp;
            string word = words[i];
            bool poss = true;
            map<char, bool> taken;
            for (int j = 0; j < word.size(); j++)
            {
                if (mp.find(pattern[j]) == mp.end())
                {
                    if (!taken[word[j]])
                    {
                        mp[pattern[j]] = word[j];
                        taken[word[j]] = true;
                    }
                    else
                    {
                        poss = false;
                        break;
                    }
                }
                else
                {
                    if (mp[pattern[j]] != word[j])
                    {
                        poss = false;
                        break;
                    }
                }
            }
            if (poss)
            {
                result.push_back(word);
            }
        }
        return result;
    }
};