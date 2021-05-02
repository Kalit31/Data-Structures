#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        sort(intervals.begin(), intervals.end());
        int q = queries.size();
        vector<array<int, 2>> arr(q);
        for (int i = 0; i < q; i++)
        {
            arr[i] = {queries[i], i};
        }
        sort(arr.begin(), arr.end());
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        map<int, int> cnt;
        vector<int> result(q, -1);

        int j = 0;
        int n = intervals.size();

        for (int i = 0; i < arr.size(); i++)
        {
            array<int, 2> curr = arr[i];
            int val = curr[0];
            while (j < n && intervals[j][0] <= val)
            {
                int len = intervals[j][1] - intervals[j][0] + 1;
                pq.push({intervals[j][1], len});
                cnt[len]++;
                j++;
            }
            while (!pq.empty() && pq.top()[0] < val)
            {
                int len = pq.top()[1];
                cnt[len]--;
                if (cnt[len] == 0)
                {
                    cnt.erase(len);
                }
                pq.pop();
            }
            if (!cnt.empty())
            {
                result[curr[1]] = cnt.begin()->first;
            }
        }

        return result;
    }
};