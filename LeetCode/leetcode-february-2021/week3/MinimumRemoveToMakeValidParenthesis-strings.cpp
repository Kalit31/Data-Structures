#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        string newString = "";
        int open = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                open++;
            }
            else if (ch == ')')
            {
                if (open == 0)
                {
                    continue;
                }
                open--;
            }
            newString += ch;
        }
        string result = "";
        for (int i = newString.size() - 1; i >= 0; i--)
        {
            if (newString[i] == '(' && open > 0)
            {
                open--;
            }
            else
            {
                result += newString[i];
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};