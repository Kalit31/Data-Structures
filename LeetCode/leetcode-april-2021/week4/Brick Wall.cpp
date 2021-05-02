#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        map<int, int> mp;

        for (int i = 0; i < wall.size(); i++)
        {
            int currWidth = 0;
            //exclude the case with all the bricks
            for (int j = 0; j < wall[i].size() - 1; j++)
            {
                currWidth += wall[i][j];
                mp[currWidth]++;
            }
        }

        int possibleCut = 0;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            possibleCut = max(possibleCut, it->second);
        }
        return wall.size() - possibleCut;
    }
};