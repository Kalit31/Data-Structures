#include <bits/stdc++.h>
using namespace std;

//Stack solution
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

class Solution
{
public:
    // Brute force, check every substring
    bool isValid(string &s, int l, int r)
    {
        int num = 0;
        for (int i = l; i <= r; i++)
        {
            if (s[i] == '(')
            {
                num++;
            }
            else
            {
                num--;
                if (num < 0)
                {
                    return false;
                }
            }
        }
        return num == 0;
    }

    //DP soln
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};