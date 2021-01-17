#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;

        int maxArea = 0;
        int top;
        int areaTop;

        int i = 0;
        while (i < n)
        {
            if (st.empty() || heights[st.top()] <= heights[i])
                st.push(i++);
            else
            {
                top = st.top();
                st.pop();

                if (st.empty())
                    areaTop = heights[top] * i;

                else
                    areaTop = heights[top] * (i - st.top() - 1);

                if (maxArea < areaTop)
                    maxArea = areaTop;
            }
        }

        while (!st.empty())
        {
            top = st.top();
            st.pop();

            if (st.empty())
                areaTop = heights[top] * i;
            else
                areaTop = heights[top] * (i - st.top() - 1);

            if (maxArea < areaTop)
                maxArea = areaTop;
        }

        return maxArea;
    }
};