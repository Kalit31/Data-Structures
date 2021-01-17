#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double time = 0;
        int n = customers.size();
        int chefIdle = 0;
        int currTime = 0;
        for (int i = 0; i < n; i++)
        {
            if (chefIdle < customers[i][0])
            {
                time += customers[i][1];
                chefIdle = customers[i][0] + customers[i][1];
            }
            else
            {
                time += (chefIdle - customers[i][0]) + customers[i][1];
                chefIdle = chefIdle + customers[i][1];
            }
        }
        return time / n;
    }
};