#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
        {
            return false;
        }
        while (n != 1)
        {
            if (n % 3 != 0)
            {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};

// 3^19 = 1162261467
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return (n > 0) && (1162261467 % n == 0);
    }
};