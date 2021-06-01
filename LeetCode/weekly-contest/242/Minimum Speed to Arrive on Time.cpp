#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double tookTime(int s, vector<int> &dist)
    {
        double tim = 0;
        int n = dist.size();
        for (int i = 0; i < n - 1; i++)
        {
            tim += (1.0 * dist[i]) / s;
            tim = ceil(tim);
        }
        tim += (1.0 * dist[n - 1]) / s;
        return tim;
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int n = dist.size();
        int lo = 1;
        int hi = 1e7 + 5;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            double tim = tookTime(mid, dist);
            if (tim <= hour)
            {
                //works
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                //incr speed
                lo = mid + 1;
            }
        }
        return ans;
    }
};