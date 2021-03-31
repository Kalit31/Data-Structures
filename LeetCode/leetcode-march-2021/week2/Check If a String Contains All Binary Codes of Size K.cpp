#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        string toFind = "";
        for (int i = 0; i < k; i++)
        {
            toFind += '0';
        }
        set<string> st;
        int n = s.size();
        for (int i = 0; i <= n - k; i++)
        {
            string t = s.substr(i, k);
            st.insert(t);
        }

        for (int i = 0; i < (1 << k); i++)
        {
            string t = toFind;
            for (int j = 0; j < k; j++)
            {
                if (i & (1 << j))
                {
                    t[j] = '1';
                }
            }

            if (st.find(t) == st.end())
            {
                return false;
            }
        }
        return true;
    }
};