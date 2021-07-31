#include <bits/stdc++.h>
using namespace std;

//O(n^2 * m * lg(m))
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int l = 0; l < n; l++)
        {
            vector<int> curr(m, 0);
            for (int r = l; r < n; r++)
            {
                for (int i = 0; i < m; i++)
                {
                    curr[i] += matrix[i][r];
                }
                set<int> s;
                s.insert(0);
                int currSum = 0;
                for (int i = 0; i < m; i++)
                {
                    currSum += curr[i];
                    auto it = s.lower_bound(currSum - k);
                    if (it != s.end())
                    {
                        ans = max(ans, currSum - (*it));
                    }
                    s.insert(currSum);
                }
            }
        }
        return ans;
    }
};

//O(n^2 * m^2)
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int l = 0; l < n; l++)
        {
            vector<int> curr(m, 0);
            for (int r = l; r < n; r++)
            {
                for (int i = 0; i < m; i++)
                {
                    curr[i] += matrix[i][r];
                }
                vector<int> pref(m, 0);
                pref[0] = curr[0];
                for (int i = 1; i < m; i++)
                {
                    pref[i] = pref[i - 1] + curr[i];
                }
                for (int i = 0; i < m; i++)
                {
                    for (int j = i; j < m; j++)
                    {
                        int currSum = pref[j] - (i > 0 ? pref[i - 1] : 0);
                        if (currSum <= k)
                        {
                            ans = max(ans, currSum);
                        }
                    }
                }
            }
        }
        return ans;
    }
};