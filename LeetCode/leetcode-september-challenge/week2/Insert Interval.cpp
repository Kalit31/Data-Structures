#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] < b[0];
    }

    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), comp);

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= (ans.back())[1])
            {
                if (intervals[i][1] < (ans.back())[1])
                {
                    continue;
                }
                ans.back()[1] = intervals[i][1];
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};