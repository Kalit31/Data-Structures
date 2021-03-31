#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //map<vector<int>,bool> mp;
    vector<vector<int>> result;
    //bool visited[101][31];

    void build(vector<int> &candidates, vector<int> t, int currSum, int target, int ind)
    {
        if (currSum > target)
        {
            return;
        }
        else if (currSum == target)
        {
            result.push_back(t);
            return;
        }
        else
        {
            for (int i = ind; i < candidates.size(); i++)
            {
                if (i > ind && candidates[i] == candidates[i - 1])
                    continue;
                if (candidates[i] + currSum > target)
                    break;

                t.push_back(candidates[i]);
                build(candidates, t, currSum + candidates[i], target, i + 1);
                t.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        result.clear();
        // memset(visited,false,sizeof(visited));
        vector<int> t;
        build(candidates, t, 0, target, 0);
        return result;
    }
};