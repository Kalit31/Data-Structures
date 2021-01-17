#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reachNumber(int target)
    {
        target = abs(target);
        if (target == 0)
            return 0;
        int moves = 0;
        int currSum = 0;
        while (true)
        {
            if (currSum > target)
            {
                if ((currSum - target) % 2 == 0)
                {
                    return moves;
                }
            }
            moves++;
            currSum += moves;
            if (currSum == target)
            {
                return moves;
            }
        }
        return 0;
    }
};