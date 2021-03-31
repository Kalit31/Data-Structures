#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return 1;
        }

        int curr = nums[1] - nums[0];
        int cnt = curr != 0 ? 2 : 1;

        for (int i = 2; i < n; i++)
        {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && curr <= 0) || (diff < 0 && curr >= 0))
            {
                cnt++;
                curr = diff;
            }
        }

        return cnt;
    }
};