#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numDifferentIntegers(string word)
    {
        string currNum = "";
        set<string> s;
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];
            if (ch >= 'a' && ch <= 'z')
            {
                if (currNum.size() != 0)
                {
                    while (currNum.size() > 0 && currNum[0] == '0')
                    {
                        currNum.erase(currNum.begin());
                    }
                    s.insert(currNum);
                    currNum = "";
                }
            }
            else
            {
                currNum += ch;
            }
        }
        if (currNum.size() != 0)
        {
            while (currNum.size() > 0 && currNum[0] == '0')
            {
                currNum.erase(currNum.begin());
            }
            s.insert(currNum);
            currNum = "";
        }
        return s.size();
    }
};