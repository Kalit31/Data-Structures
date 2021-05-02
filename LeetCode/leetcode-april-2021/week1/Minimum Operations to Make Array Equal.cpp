#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(int n)
    {
        if (n & 1)
        {
            int toMake = 2 * (n / 2 + 1) - 1;
            int moves = 0;
            for (int i = 0; i <= n / 2; i++)
            {
                int curr = 2 * i + 1;
                moves += abs(curr - toMake);
            }
            return moves;
        }
        else
        {
            int toMake = n;
            int moves = 0;
            for (int i = 0; i < n / 2; i++)
            {
                int curr = 2 * i + 1;
                moves += abs(curr - toMake);
            }
            return moves;
        }
        return 0;
    }
};

// Simple formula
int minOperations(int n)
{
    int cnt = n / 2;
    return cnt * (cnt + n % 2);
}