#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nextChar(char ch)
    {
        if (ch == 'a')
        {
            return 'e';
        }
        else if (ch == 'e')
        {
            return 'i';
        }
        else if (ch == 'i')
        {
            return 'o';
        }
        else if (ch == 'o')
        {
            return 'u';
        }
        else
        {
            return 'a';
        }
    }

    int longestBeautifulSubstring(string word)
    {
        int n = word.size();
        int maxLen = 0;
        int currLen = 0;
        char currChar = 'a';
        int i = 0;
        while (i < n && word[i] != 'a')
        {
            i++;
        }
        for (; i < n;)
        {
            while (i < n && word[i] == currChar)
            {
                i++;
                currLen++;
            }
            if (currChar == 'u')
            {
                maxLen = max(maxLen, currLen);
                currLen = 0;
            }
            if (word[i] == nextChar(currChar))
            {
                currChar = nextChar(currChar);
            }
            else
            {
                while (i < n && word[i] != 'a')
                {
                    i++;
                }
                currChar = 'a';
                currLen = 0;
            }
        }
        return maxLen;
    }
};