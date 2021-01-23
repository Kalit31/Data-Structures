#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 != n2)
        {
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < n1; i++)
        {
            freq1[word1[i] - 'a']++;
        }
        for (int i = 0; i < n2; i++)
        {
            freq2[word2[i] - 'a']++;
            if (freq1[word2[i] - 'a'] == 0)
            {
                return false;
            }
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }
        return true;
    }
};