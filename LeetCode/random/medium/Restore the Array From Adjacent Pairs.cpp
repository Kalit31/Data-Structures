#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &adjacentPairs)
    {
        int num = adjacentPairs.size();
        unordered_map<int, vector<int>> mp;
        int leftMost;
        for (int i = 0; i < num; i++)
        {
            vector<int> curr = adjacentPairs[i];
            mp[curr[0]].push_back(curr[1]);
            mp[curr[1]].push_back(curr[0]);
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if ((it->second).size() == 1)
            {
                leftMost = it->first;
            }
        }
        vector<int> ans;
        ans.push_back(leftMost);
        unordered_map<int, bool> visited;
        visited[leftMost] = true;
        while (ans.size() != (num + 1))
        {
            vector<int> curr = mp[leftMost];
            int next;
            for (int val : curr)
            {
                if (!visited[val])
                {
                    next = val;
                    break;
                }
            }
            visited[next] = true;
            ans.push_back(next);
            leftMost = next;
        }
        return ans;
    }
};