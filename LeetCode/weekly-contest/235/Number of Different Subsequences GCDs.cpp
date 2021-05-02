#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int N = 2e5 + 1;
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        vector<int> factors(N, 0);
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j * j <= nums[i]; j++)
            {
                if (nums[i] % j == 0)
                {
                    int f1 = j;
                    int f2 = nums[i] / j;

                    factors[f1] = __gcd(factors[f1], nums[i]);
                    factors[f2] = __gcd(factors[f2], nums[i]);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < N; i++)
        {
            if (factors[i] == i)
                ans++;
        }
        return ans;
    }
};