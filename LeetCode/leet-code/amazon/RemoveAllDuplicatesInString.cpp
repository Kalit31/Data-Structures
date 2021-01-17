#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string S)
    {
        stack<char> st;
        st.push(S[0]);
        for (int i = 1; i < S.length(); i++)
        {
            if (!st.empty() && st.top() == S[i])
            {
                while (!st.empty() && st.top() == S[i])
                {
                    st.pop();
                }
            }
            else
            {
                st.push(S[i]);
            }
        }
        string result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};