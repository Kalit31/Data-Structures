#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<int> result(3, 0);
        for (auto curr : triplets)
        {
            if (curr[0] <= target[0] && curr[1] <= target[1] && curr[2] <= target[2])
            {
                result[0] = max(result[0], curr[0]);
                result[1] = max(result[1], curr[1]);
                result[2] = max(result[2], curr[2]);
            }
        }
        return result == target;
    }
};