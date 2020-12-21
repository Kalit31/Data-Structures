#include <bits/stdc++.h>
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        int rand = 41;
        while (rand > 40)
        {
            rand = 7 * (rand7() - 1) + rand7();
            //rand = 8*rand7()-7;
        }
        return 1 + rand % 10;
    }
};