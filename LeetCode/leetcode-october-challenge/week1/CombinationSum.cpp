#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void build(vector<vector<int>> &res, vector<int> t, vector<int> A, int target, int curr, int ind)
    {
        if (curr > target)
        {
            return;
        }
        else if (curr == target)
        {
            res.push_back(t);
        }
        else
        {
            for (int i = ind; i < A.size(); i++)
            {
                t.push_back(A[i]);
                build(res, t, A, target, curr + A[i], i);
                t.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> t;
        build(result, t, candidates, target, 0, 0);
        return result;
    }
};