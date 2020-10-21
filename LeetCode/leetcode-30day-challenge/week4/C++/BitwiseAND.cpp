#include <bits/stdc++.h>
using namespace std;

//Type: Maths
//Approach:
//Complexity: O(lgN) time

class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int result = 0;
        while (m != n)
        {
            m = m >> 1;
            n = n >> 1;
            result++;
        }
        return m << result;
    }
};