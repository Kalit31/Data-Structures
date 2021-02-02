#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int n = nums.size();
        int diff = INT_MAX;
        priority_queue<int> pq;
        int currMin = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int toPush = nums[i];
            if (nums[i] % 2)
            {
                toPush = nums[i] * 2;
            }
            pq.push(toPush);
            currMin = min(currMin, toPush);
        }
        while (pq.top() % 2 == 0)
        {
            diff = min(diff, pq.top() - currMin);
            currMin = min(currMin, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        diff = min(diff, pq.top() - currMin);
        return diff;
    }
};