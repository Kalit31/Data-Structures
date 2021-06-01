#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 0;
        }
        int reachable = nums[0];
        int steps = nums[0];
        int jumps = 1;

        for (int i = 1; i < n - 1; i++)
        {
            reachable = max(reachable, i + nums[i]);
            steps--;
            if (steps == 0)
            {
                jumps++;
                steps = reachable - i;
            }
        }
        return jumps;
    }
};

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> numberOfJumps(n, INT_MAX);
        numberOfJumps[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (i - j <= nums[j])
                {
                    numberOfJumps[i] = min(numberOfJumps[i], numberOfJumps[j] + 1);
                }
            }
        }
        return numberOfJumps[n - 1];
    }
};