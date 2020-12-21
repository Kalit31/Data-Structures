#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int countCap = 0;
        bool isCapFirst = (word[0] >= 65 && word[0] <= 90);
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 65 && word[i] <= 90)
            {
                countCap++;
            }
        }
        if (!isCapFirst && countCap == 0)
        {
            return true;
        }
        if (countCap == word.length())
        {
            return true;
        }
        if (isCapFirst && countCap == 1)
        {
            return true;
        }
        return false;
    }
};