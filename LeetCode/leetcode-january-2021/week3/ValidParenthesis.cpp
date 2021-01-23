#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> s1;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                s1.push('(');
            }
            else if (s[i] == ')')
            {
                if (s1.empty())
                {
                    return false;
                }
                if (s1.top() != '(')
                {
                    return false;
                }
                s1.pop();
            }
            else if (s[i] == '{')
            {
                s1.push('{');
            }
            else if (s[i] == '}')
            {
                if (s1.empty())
                {
                    return false;
                }
                if (s1.top() != '{')
                {
                    return false;
                }
                s1.pop();
            }
            else if (s[i] == '[')
            {
                s1.push('[');
            }
            else if (s[i] == ']')
            {
                if (s1.empty())
                {
                    return false;
                }
                if (s1.top() != '[')
                {
                    return false;
                }
                s1.pop();
            }
        }
        return (s1.empty());
    }
};