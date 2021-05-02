#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string truncateSentence(string s, int k)
    {
        string result = "";
        string curr = "";
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (cnt + 1 == k)
                {
                    result += curr;
                }
                else
                {
                    result += curr + " ";
                }
                curr = "";
                cnt++;
            }
            else
            {
                curr += s[i];
            }
            if (cnt == k)
            {
                break;
            }
        }
        if (cnt != k)
            result += curr;
        return result;
    }
};