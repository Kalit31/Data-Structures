#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        else if (dividend == INT_MAX && divisor == 1)
        {
            return INT_MAX;
        }
        long a = abs(dividend);
        long b = abs(divisor);
        long ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

        while (a >= b)
        {
            long tmp = b, m = 1;
            while (tmp << 1 <= a)
            {
                tmp <<= 1;
                m <<= 1;
            }
            a -= tmp;
            ans += m;
        }
        return sign * ans;
    }
};