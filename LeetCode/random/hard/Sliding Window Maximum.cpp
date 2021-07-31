#include <bits/stdc++.h>
using namespace std;

//O(N)
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> result;

        deque<int> q;

        int i = 0;
        for (int j = 0; j < n; j++)
        {
            while (!q.empty() && nums[q.back()] < nums[j])
            {
                q.pop_back();
            }
            q.push_back(j);

            while (q.front() < i)
            {
                q.pop_front();
            }

            if (j + 1 >= k)
            {
                result.push_back(nums[q.front()]);
                i++;
            }
        }

        return result;
    }
};

//O(N log k)
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> result;
        multiset<int, greater<int>> s;

        int i = 0;
        int j = 0;
        for (; j < k; j++)
        {
            s.insert(nums[j]);
        }
        result.push_back(*(s.begin()));

        for (; j < n; j++)
        {
            s.insert(nums[j]);
            auto it = s.find(nums[i]);
            s.erase(it);
            i++;
            result.push_back(*(s.begin()));
        }
        return result;
    }
};