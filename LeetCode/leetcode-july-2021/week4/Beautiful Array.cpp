#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> beautifulArray(int n)
    {
        vector<int> result = {1};
        while (result.size() < n)
        {
            vector<int> odd;
            for (int x : result)
            {
                if (2 * x - 1 <= n)
                    odd.push_back(2 * x - 1);
            }
            vector<int> even;
            for (int x : result)
            {
                if (2 * x <= n)
                    even.push_back(2 * x);
            }
            result.clear();
            for (int x : odd)
            {
                result.push_back(x);
            }
            for (int x : even)
            {
                result.push_back(x);
            }
        }
        return result;
    }
};