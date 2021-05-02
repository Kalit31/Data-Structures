#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push({s[i], 1});
            }
            else
            {
                auto it = st.top();
                if (it.first == s[i])
                {
                    st.push({s[i], it.second + 1});
                }
                else
                {
                    st.push({s[i], 1});
                }
                it = st.top();
                if (it.second == k)
                {
                    for (int j = 0; j < k; j++)
                    {
                        st.pop();
                    }
                }
            }
        }
        string result = "";
        while (!st.empty())
        {
            result = (st.top()).first + result;
            st.pop();
        }
        return result;
    }
};