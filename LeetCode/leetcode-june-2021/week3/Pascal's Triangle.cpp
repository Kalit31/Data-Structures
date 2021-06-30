#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.push_back({1});
        for (int i = 2; i <= numRows; i++)
        {
            vector<int> curr;
            curr.push_back(1);
            for (int j = 0; j < result.back().size() - 1; j++)
            {
                curr.push_back((result.back())[j] + (result.back())[j + 1]);
            }
            curr.push_back(1);
            result.push_back(curr);
        }
        return result;
    }
};