#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        string s1 = "";
        for (char ch : firstWord)
        {
            s1 += to_string((int)(ch - 'a'));
        }
        string s2 = "";
        for (char ch : secondWord)
        {
            s2 += to_string((int)(ch - 'a'));
        }
        string s3 = "";
        for (char ch : targetWord)
        {
            s3 += to_string((int)(ch - 'a'));
        }
        return (stoi(s1) + stoi(s2) == stoi(s3));
    }
};
