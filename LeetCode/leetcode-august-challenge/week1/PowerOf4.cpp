#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if (num <= 0)
        {
            return false;
        }

        while (num != 1)
        {
            if (num % 4)
            {
                return false;
            }
            num = num >> 2;
        }
        return true;
    }
};

class Solution
{
public:
    // power of four = power of two, with the set bit appearing at an odd position
    bool isPowerOfFour(int num)
    {
        return num > 0 and (num & (num - 1)) == 0 and (num & 0x55555555);
    }
};