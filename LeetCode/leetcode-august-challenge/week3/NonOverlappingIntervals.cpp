#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct myComp
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            return a[1] < b[1];
        }
    };

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int remove = 0;
        if (intervals.size() == 0)
        {
            return remove;
        }
        sort(intervals.begin(), intervals.end(), myComp());
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prevEnd)
            {
                remove++;
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }

        return remove;
    }
};