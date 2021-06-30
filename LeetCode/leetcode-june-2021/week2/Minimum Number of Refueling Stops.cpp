#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();
        int cnt = 0;
        int currFuel = startFuel;
        int currDist = 0;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            int dist = stations[i][0];
            int fuel = stations[i][1];

            while (!pq.empty() && currDist + currFuel < dist)
            {
                currFuel += pq.top();
                pq.pop();
                cnt++;
            }

            if (currDist + currFuel < dist)
            {
                return -1;
            }

            currFuel -= (dist - currDist);
            currDist = dist;

            pq.push(fuel);
        }

        while (!pq.empty() && currDist + currFuel < target)
        {
            currFuel += pq.top();
            pq.pop();
            cnt++;
        }

        if (currDist + currFuel < target)
        {
            return -1;
        }

        return cnt;
    }
};