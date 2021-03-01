#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int steps = 0;
        while (num != 0)
        {
            if (num & 1)
            {
                num--;
            }
            else
            {
                num /= 2;
            }
            steps++;
        }
        return steps;
    }
};