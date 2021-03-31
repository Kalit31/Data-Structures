#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long int sum = 0;
        for (int n : nums)
        {
            sum += n;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (sum == goal)
        {
            return 0;
        }
        else if (sum < goal)
        {
            //add numbers
            long long int toAdd = goal - sum;
            int cnt = ceil((1.0 * toAdd) / limit);
            return cnt;
        }
        else
        {
            //subtract numbers
            long long int toSub = sum - goal;
            int cnt = ceil((1.0 * toSub) / limit);
            return cnt;
        }
        return -1;
    }
};