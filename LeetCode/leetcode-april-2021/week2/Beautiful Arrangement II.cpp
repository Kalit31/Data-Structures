#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> result;

        for (int i = 1, j = n; i <= j;)
        {
            if (k > 1)
            {
                if (k % 2)
                {
                    result.push_back(i);
                    i++;
                }
                else
                {
                    result.push_back(j);
                    j--;
                }
                k--;
            }
            else
            {
                result.push_back(i);
                i++;
            }
        }

        return result;
    }
};