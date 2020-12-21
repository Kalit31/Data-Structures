#include <bits/stdc++.h>
using namespace std;

//O(N) solution
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;
        stack<int> st;
        vector<int> minNum(n, 0);
        minNum[0] = nums[0];
        for (int i = 1; i < n; i++)
            minNum[i] = min(minNum[i - 1], nums[i]);

        for (int j = n - 1; j >= 0; j--)
        {
            if (nums[j] > minNum[j])
            {
                while (!st.empty() && st.top() <= minNum[j])
                    st.pop();
                if (!st.empty() && st.top() < nums[j])
                    return true;
                st.push(nums[j]);
            }
        }
        return false;
    }
};

// O(N^2) solution
class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();

        int minNum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > minNum && nums[j] < nums[i])
                {
                    return true;
                }
            }
            minNum = min(minNum, nums[i]);
        }
        return false;
    }
};
