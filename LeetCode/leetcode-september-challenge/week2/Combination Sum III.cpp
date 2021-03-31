#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    map<vector<int>, bool> mp;
    vector<vector<int>> ans;
    int req = 0;

    void build(vector<int> tmp, int currSum, int k, int ind)
    {
        if (currSum > req || k < 0)
        {
            return;
        }
        else if (currSum == req && k == 0)
        {
            if (mp.find(tmp) == mp.end())
            {
                ans.push_back(tmp);
                mp[tmp] = true;
            }
        }
        else
        {
            for (int i = ind; i <= 9; i++)
            {
                tmp.push_back(i);
                build(tmp, currSum + i, k - 1, i + 1);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> tmp;
        req = n;
        build(tmp, 0, k, 1);
        return ans;
    }
};