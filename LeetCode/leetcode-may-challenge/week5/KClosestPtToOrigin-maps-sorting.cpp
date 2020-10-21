#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        vector<pair<long int, int>> distpts;

        for (int i = 0; i < points.size(); i++)
        {
            long int x = points[i][0];
            long int y = points[i][1];
            distpts.push_back({x * x + y * y, i});
        }
        sort(distpts.begin(), distpts.end());

        vector<vector<int>> result;

        for (int i = 0; i < K; i++)
        {
            result.push_back(points[distpts[i].second]);
        }
        return result;
    }
};