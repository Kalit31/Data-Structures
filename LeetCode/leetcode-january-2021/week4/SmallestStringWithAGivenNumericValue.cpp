#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getSmallestString(int n, int k)
    {
        string s(n, 'a');
        k -= 1 * n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (k == 0)
            {
                break;
            }
            if (k > 25)
            {
                s[i] = 'z';
                k -= 25;
            }
            else
            {
                s[i] = (char)('a' + k);
                k = 0;
            }
        }
        return s;
    }
};