#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> result;
        int sum = 0;
        for (int x : nums)
        {
            sum += x;
            result.push_back(sum);
        }
        return result;
    }
};