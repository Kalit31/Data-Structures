#include <bits/stdc++.h>
using namespace std;

//Type: Math
//Approach: Keep dividing the number by 2. At any instance, if it is not divisible by 2,
//          return false.
//Complexity: O(LgN) time

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        while (n != 1)
        {
            if (n % 2 != 0)
            {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};