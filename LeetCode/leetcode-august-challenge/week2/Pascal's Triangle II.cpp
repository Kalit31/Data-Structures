#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex < 0)
        {
            return vector<int>();
        }
        vector<int> prev = {1};
        vector<int> curr = {1};

        for (int row = 1; row <= rowIndex; row++)
        {
            curr.clear();
            curr.push_back(1);
            for (int j = 1; j < row; j++)
            {
                curr.push_back(prev[j - 1] + prev[j]);
            }
            curr.push_back(1);
            prev = curr;
        }
        return curr;
    }
};