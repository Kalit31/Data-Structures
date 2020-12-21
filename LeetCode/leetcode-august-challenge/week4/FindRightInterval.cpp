#include <bits/stdc++.h>
using namespace std;

// O(N lg N) solution
class Solution
{
public:
    int find(vector<pair<int, int>> &a, int end)
    {
        int l = 0;
        int r = a.size() - 1;
        int index = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid].first == end)
            {
                index = a[mid].second;
                break;
            }
            else if (a[mid].first > end)
            {
                index = a[mid].second;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return index;
    }

    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int n = intervals.size();
        vector<int> result(n);

        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = {intervals[i][0], i};
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            int end = intervals[i][1];
            int index = find(arr, end);
            result[i] = index;
        }

        return result;
    }
};

//O(N^2) soln
class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int n = intervals.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++)
        {
            int end = intervals[i][1];
            int start = INT_MAX;
            int index = -1;
            for (int j = 0; j < n; j++)
            {
                int currStart = intervals[j][0];
                if (currStart >= end && currStart < start)
                {
                    start = currStart;
                    index = j;
                }
            }
            result[i] = index;
        }
        return result;
    }
};