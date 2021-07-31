#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;

        vector<int> left(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (!st.empty())
            {
                if (heights[st.top()] >= heights[i])
                {
                    while (!st.empty() && heights[st.top()] >= heights[i])
                    {
                        st.pop();
                    }
                    if (!st.empty())
                    {
                        left[i] = st.top();
                    }
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
            if (!st.empty())
            {
                if (heights[st.top()] >= heights[i])
                {
                    while (!st.empty() && heights[st.top()] >= heights[i])
                    {
                        st.pop();
                    }
                    if (!st.empty())
                    {
                        right[i] = st.top();
                    }
                }
                else
                {
                    right[i] = st.top();
                }
            }
            st.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int cnt = right[i] - left[i] - 1;
            maxArea = max(maxArea, cnt * heights[i]);
        }

        return maxArea;
    }
};

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