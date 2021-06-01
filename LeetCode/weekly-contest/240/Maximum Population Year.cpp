#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> years(105, 0);
        for (int i = 0; i < logs.size(); i++)
        {
            auto curr = logs[i];
            years[curr[0] - 1950]++;
            years[curr[1] - 1950]--;
        }
        for (int i = 1; i < 105; i++)
        {
            years[i] += years[i - 1];
        }
        int maxPop = *max_element(years.begin(), years.end());
        for (int i = 0; i <= 100; i++)
        {
            if (years[i] == maxPop)
            {
                return (i + 1950);
            }
        }
        return 2050;
    }
};