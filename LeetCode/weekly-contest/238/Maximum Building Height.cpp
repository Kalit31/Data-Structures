#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end());

        for (int i = 0; i < restrictions.size() - 1; i++)
        {
            int h1 = restrictions[i][1];
            int h2 = restrictions[i + 1][1];
            int possH = h1 + restrictions[i + 1][0] - restrictions[i][0];
            if (possH > h2)
            {
                possH = h2 + (possH - h2) / 2;
            }
            else
            {
                restrictions[i + 1][1] = possH;
            }
        }

        int result = 0;

        for (int i = restrictions.size() - 1; i > 0; i--)
        {
            int h1 = restrictions[i][1];
            int h2 = restrictions[i - 1][1];
            int possH = h1 + restrictions[i][0] - restrictions[i - 1][0];
            if (possH > h2)
            {
                possH = h2 + (possH - h2) / 2;
            }
            else
            {
                restrictions[i - 1][1] = possH;
            }
            result = max(result, possH);
        }

        return result;
    }
};

//TLE Soln
class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        vector<int> maxHeight(n, 1e9 + 5);

        for (int i = 0; i < restrictions.size(); i++)
        {
            maxHeight[restrictions[i][0] - 1] = restrictions[i][1];
        }

        maxHeight[0] = 0;

        for (int i = 1; i < n; i++)
        {
            maxHeight[i] = min(maxHeight[i], maxHeight[i - 1] + 1);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            maxHeight[i] = min(maxHeight[i], maxHeight[i + 1] + 1);
        }

        return *max_element(maxHeight.begin(), maxHeight.end());
    }
};