#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
    {
        map<int, set<int>> mp;
        for (int i = 0; i < logs.size(); i++)
        {
            mp[logs[i][0]].insert(logs[i][1]);
        }
        vector<int> result(k, 0);
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            result[(it->second).size() - 1]++;
        }
        return result;
    }
};