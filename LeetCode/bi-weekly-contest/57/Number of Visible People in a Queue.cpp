#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> result(n, 0);

        stack<int> st;
        st.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            int cnt = 0;
            while (!st.empty() && heights[st.top()] <= heights[i])
            {
                cnt++;
                st.pop();
            }
            cnt += (st.empty() ? 0 : 1);
            result[i] = cnt;
            st.push(i);
        }
        return result;
    }
};