#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> result;
        int n = S.size();
        set<string> st;

        for (int i = 0; i < (1 << n); i++)
        {
            string newS = S;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    char ch = newS[j];
                    ch = toupper(ch);
                    newS[j] = ch;
                }
                else
                {
                    char ch = newS[j];
                    ch = tolower(ch);
                    newS[j] = ch;
                }
            }
            st.insert(newS);
        }
        for (string str : st)
        {
            result.push_back(str);
        }

        return result;
    }
};