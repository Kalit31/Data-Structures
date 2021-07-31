#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        st.push(INT_MAX);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                int toRemove = st.top();
                st.pop();
                int neighbor = min(arr[i], st.top());
                ans += toRemove * neighbor;
            }
            st.push(arr[i]);
        }
        while (st.size() > 2)
        {
            int toRemove = st.top();
            st.pop();
            ans += toRemove * st.top();
        }
        return ans;
    }
};

class Solution
{
public:
    int build(vector<int> &arr, vector<vector<int>> &dp, int l, int r)
    {
        if (l >= r)
        {
            return 0;
        }
        if (dp[l][r] != -1)
        {
            return dp[l][r];
        }
        int ans = INT_MAX;
        for (int part = l; part < r; part++)
        {
            int max1 = arr[l];
            for (int i = l; i <= part; i++)
            {
                max1 = max(max1, arr[i]);
            }
            int max2 = arr[part + 1];
            for (int i = part + 1; i <= r; i++)
            {
                max2 = max(max2, arr[i]);
            }
            int currAns = build(arr, dp, l, part) + build(arr, dp, part + 1, r) + max1 * max2;
            ans = min(ans, currAns);
        }
        return dp[l][r] = ans;
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return build(arr, dp, 0, n - 1);
    }
};