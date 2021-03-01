#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        int j = 0;
        string result = "";
        while (i < n && j < m)
        {
            result += word1[i++];
            result += word2[j++];
        }
        while (i < n)
        {
            result += word1[i++];
        }
        while (j < m)
        {
            result += word2[j++];
        }
        return result;
    }
};