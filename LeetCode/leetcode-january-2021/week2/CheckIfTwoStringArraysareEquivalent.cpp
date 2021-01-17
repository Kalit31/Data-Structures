#include <bits/stdc++.h>
using namespace std;

//Less memory but slow
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int n = word1.size();
        int m = word2.size();
        int i = 0;
        int j = 0;
        int cI = 0;
        int cJ = 0;

        while (true)
        {
            if (i == n && j == m)
            {
                return true;
            }
            else if (i == n)
            {
                return false;
            }
            else if (j == m)
            {
                return false;
            }
            if (cI == word1[i].size() && cJ == word2[j].size())
            {
                cI = 0;
                i++;
                cJ = 0;
                j++;
            }
            else if (cI == word1[i].size())
            {
                cI = 0;
                i++;
            }
            else if (cJ == word2[j].size())
            {
                cJ = 0;
                j++;
            }
            else
            {
                //cout<<word1[i][cI]<<" "<<word2[j][cJ]<<endl;
                if (word1[i][cI] != word2[j][cJ])
                {
                    return false;
                }
                cI++;
                cJ++;
            }
        }

        return true;
    }
};

//More memory but fast
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1, s2;
        for (int i = 0; i < word1.size(); i++)
        {
            s1 += word1[i];
        }
        for (int i = 0; i < word2.size(); i++)
        {
            s2 += word2[i];
        }
        return s1 == s2;
    }
};