#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<array<int, 3>> pq;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                pq.push({nums1[i] + nums2[j], nums1[i], nums2[j]});
                if (pq.size() > k)
                {
                    pq.pop();
                }
            }
        }
        vector<vector<int>> result;

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            result.push_back({curr[1], curr[2]});
        }
        reverse(result.begin(), result.end());
        return result;
    }
};