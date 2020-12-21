#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int num = x ^ y;
        int count = 0;
        while (num != 0)
        {
            count += num % 2 == 0 ? 0 : 1;
            num /= 2;
        }
        return count;
    }
};