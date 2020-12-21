#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 1)
        {
            return x;
        }
        double result = 1;
        bool isNeg = false;
        long long int exp = n;
        if (n < 0)
        {
            isNeg = true;
            exp = -exp;
        }
        while (exp)
        {
            if (exp & 1)
            {
                result *= x;
                exp--;
            }
            x = x * x;
            exp = exp >> 1;
        }
        if (isNeg)
        {
            return (1.0 / result);
        }
        return result;
    }
};