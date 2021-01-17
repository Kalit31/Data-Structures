#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int maxGain = 0;
        stack<char> s1;
        stack<char> s2;
        int n = s.size();

        char toFind = x > y ? 'a' : 'b';
        char sFind = x > y ? 'b' : 'a';
        int minN = min(x, y);
        int maxN = max(x, y);

        for (int i = 0; i < n; i++)
        {
            if (!s1.empty() && s1.top() == toFind && s[i] == sFind)
            {
                maxGain += maxN;
                s1.pop();
            }
            else
            {
                s1.push(s[i]);
            }
        }
        while (!s1.empty())
        {
            char ch = s1.top();
            s1.pop();
            if (!s2.empty() && s2.top() == toFind && ch == sFind)
            {
                maxGain += minN;
                s2.pop();
            }
            else
            {
                s2.push(ch);
            }
        }
        return maxGain;
    }
};