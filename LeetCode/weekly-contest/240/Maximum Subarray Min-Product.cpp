#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;

    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<ll> prefSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            prefSum[i] = prefSum[i - 1] + (ll)nums[i - 1];
        }
        stack<int> st;
        vector<int> left(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                left[i] = -1;
            }
            else if (nums[i] > nums[st.top()])
            {
                left[i] = st.top();
            }
            else
            {
                while (!st.empty() && nums[i] <= nums[st.top()])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    left[i] = -1;
                }
                else
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
            else if (nums[i] > nums[st.top()])
            {
                right[i] = st.top();
            }
            else
            {
                while (!st.empty() && nums[i] <= nums[st.top()])
                {
                    st.pop();
                }
                if (st.empty())
                {
                    right[i] = n;
                }
                else
                {
                    right[i] = st.top();
                }
            }
            st.push(i);
        }

        ll maxProd = 0;
        for (int i = 0; i < n; i++)
        {
            int l = left[i];
            int r = right[i];
            ll sum = prefSum[r] - prefSum[l + 1];
            maxProd = max(maxProd, sum * nums[i]);
        }
        return maxProd % mod;
    }
};