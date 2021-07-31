#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        const int mod = 1e9 + 7;
        vector<int> left(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                left[i] = -1;
            }
            else
            {
                while (!st.empty() && arr[st.top()] > arr[i])
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    left[i] = st.top();
                }
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        vector<int> right(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                right[i] = n;
            }
            else
            {
                while (!st.empty() && arr[st.top()] >= arr[i])
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    right[i] = st.top();
                }
            }
            st.push(i);
        }

        ll ans = 0;

        for (int i = 0; i < n; i++)
        {
            ll eleToLeft = i - left[i];
            ll eleToRight = right[i] - i;

            ll cnt = eleToLeft * eleToRight;
            cnt = cnt % mod;
            ans = (ans + (arr[i] * cnt) % mod) % mod;
        }
        return ans;
    }
};