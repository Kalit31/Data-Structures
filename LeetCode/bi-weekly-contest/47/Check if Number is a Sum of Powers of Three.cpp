#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n % 3 != 0)
        {
            n--;
        }
        while (n != 0)
        {
            int curr = 1;
            while (n % curr == 0)
            {
                curr *= 3;
            }
            curr /= 3;
            if (curr == 1)
            {
                return false;
            }
            n /= curr;
            n--;
            if (n < 0)
            {
                return false;
            }
        }
        return true;
    }
};