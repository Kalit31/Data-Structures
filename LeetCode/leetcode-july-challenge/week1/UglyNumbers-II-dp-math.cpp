#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        int indexTwo = 0;
        int indexThree = 0;
        int indexFive = 0;

        vector<int> uglyNum(n);
        uglyNum[0] = 1;

        for (int i = 1; i < n; i++)
        {
            uglyNum[i] = min(uglyNum[indexTwo] * 2, min(uglyNum[indexThree] * 3, uglyNum[indexFive] * 5));
            if (uglyNum[i] == uglyNum[indexTwo] * 2)
            {
                indexTwo++;
            }
            if (uglyNum[i] == uglyNum[indexThree] * 3)
            {
                indexThree++;
            }
            if (uglyNum[i] == uglyNum[indexFive] * 5)
            {
                indexFive++;
            }
        }
        return uglyNum[n - 1];
    }
};