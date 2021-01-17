#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumBinaryString(string binary)
    {
        int n = binary.size();
        string result = string(n, '1');
        int z = 0;
        int o = 0;
        for (int i = 0; i < n; i++)
        {
            if (binary[i] == '0')
            {
                z++;
            }
            else if (z == 0)
            {
                o++;
            }
        }
        if (o < n)
        {
            result[o + z - 1] = '0';
        }
        return result;
    }
};