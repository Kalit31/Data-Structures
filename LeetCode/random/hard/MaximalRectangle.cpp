#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
        {
            return 0;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i - 1][j] == '0')
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1 + dp[i - 1][j];
                }
            }
        }

        int maxArea = 0;

        for (int i = 1; i <= n; i++)
        {
            vector<int> left(m);
            stack<int> st;
            for (int j = 0; j < m; j++)
            {
                if (st.empty())
                {
                    left[j] = -1;
                }
                else if (dp[i][st.top()] < dp[i][j])
                {
                    left[j] = st.top();
                }
                else
                {
                    while (!st.empty() && dp[i][st.top()] >= dp[i][j])
                    {
                        st.pop();
                    }
                    if (st.empty())
                    {
                        left[j] = -1;
                    }
                    else
                    {
                        left[j] = st.top();
                    }
                }
                st.push(j);
            }
            while (!st.empty())
            {
                st.pop();
            }
            vector<int> right(m);
            for (int j = m - 1; j >= 0; j--)
            {
                if (st.empty())
                {
                    right[j] = m;
                }
                else if (dp[i][st.top()] < dp[i][j])
                {
                    right[j] = st.top();
                }
                else
                {
                    while (!st.empty() && dp[i][st.top()] >= dp[i][j])
                    {
                        st.pop();
                    }
                    if (st.empty())
                    {
                        right[j] = m;
                    }
                    else
                    {
                        right[j] = st.top();
                    }
                }
                st.push(j);
            }

            for (int j = 0; j < m; j++)
            {
                maxArea = max(maxArea, dp[i][j] * (right[j] - left[j] - 1));
            }
        }
        return maxArea;
    }
};