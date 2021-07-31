#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> codes = {0, 1};
        for (int i = 2; i <= n; i++)
        {
            int sz = codes.size();
            for (int j = sz - 1; j >= 0; j--)
            {
                codes.push_back(codes[j]);
            }
            int half = (codes.size() / 2);
            for (int j = half; j < codes.size(); j++)
            {
                codes[j] = (1 << (i - 1)) + codes[j];
            }
        }
        return codes;
    }
};