#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minInsertions(string s)
    {
        int curr = 0;
        int insertions = 0;
        int n = s.size();
        for (int i = 0; i < n;)
        {
            if (s[i] == '(')
            {
                curr++;
                i++;
            }
            else
            {
                if (curr == 0)
                {
                    //we need a left parentheses
                    insertions++;
                    curr++;
                }
                if (i == (n - 1) || s[i + 1] == '(')
                {
                    //we need a right parentheses
                    insertions++;
                    curr--;
                    i++;
                }
                else
                {
                    curr--;
                    i += 2;
                }
            }
        }
        // add remaining right parentheses
        insertions += curr * 2;
        return insertions;
    }
};