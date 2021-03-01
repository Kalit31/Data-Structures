#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int score = 0;
        stack<int> st;
        st.push(0);

        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '(')
            {
                st.push(0);
            }
            else
            {
                int tp1 = st.top();
                st.pop();
                int tp2 = st.top();
                st.pop();
                st.push(tp2 + max(tp1 * 2, 1));
            }
        }
        return st.top();
    }
};

//Another approach
class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '(')
            {
                bal++;
            }
            else
            {
                bal--;
                if (S[i] == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
};