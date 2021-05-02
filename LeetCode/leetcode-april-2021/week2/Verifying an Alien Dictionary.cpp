#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        map<char, int> mp;
        for (int i = 0; i < order.size(); i++)
        {
            mp[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; i++)
        {
            string word1 = words[i];
            string word2 = words[i + 1];
            int j = 0;
            for (; j < word1.size() && j < word2.size(); j++)
            {
                if (mp[word1[j]] > mp[word2[j]])
                {
                    return false;
                }
                else if (mp[word1[j]] < mp[word2[j]])
                {
                    break;
                }
            }
            if (j == word2.size() && word1.size() > word2.size())
            {
                return false;
            }
        }
        return true;
    }
};