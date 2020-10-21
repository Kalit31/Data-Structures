#include <bits/stdc++.h>
using namespace std;

//Type: Bit Manipulation
//Approach: The complement in binary would be
//          2^(number of bits the number can be represented in) - number - 1
//Complexity: O(number of bits) time

class Solution
{
public:
    int findComplement(int num)
    {
        int bits = 0;
        long int n = num;
        while (n != 0)
        {
            bits++;
            n /= 2;
        }
        unsigned long int t = pow(2, bits) - 1;
        return (int)(t - num);
    }
};

class Solution
{
public:
    int findComplement(int num)
    {
        long max = 1;
        while (max <= num)
        {
            max = max << 1;
        }

        if (max > 1)
            --max;

        return (max ^ num);
    }
};

class Solution
{
public:
    int findComplement(int num)
    {
        int i = 0;
        int ans = 0;
        while (num != 0)
        {
            if ((num & 1) == 0)
                ans += 1 << i;
            i++;
            num >>= 1;
        }
        return ans;
    }
};