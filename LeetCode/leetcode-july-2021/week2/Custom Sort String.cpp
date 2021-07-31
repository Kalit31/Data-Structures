#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string str)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < str.size(); i++)
        {
            freq[str[i] - 'a']++;
        }
        string result = "";
        for (int i = 0; i < order.size(); i++)
        {
            string toAdd(freq[order[i] - 'a'], order[i]);
            result += toAdd;
            freq[order[i] - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++)
        {
            string toAdd(freq[i], char(97 + i));
            result += toAdd;
        }
        return result;
    }
};