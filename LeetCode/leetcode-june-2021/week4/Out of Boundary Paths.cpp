#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        const int mod = 1e9 + 7;
        const int N = 51;
        ll dp[N][N][N];
        memset(dp, 0, sizeof(dp));
        vector<int> dirX = {1, 0, -1, 0};
        vector<int> dirY = {0, 1, 0, -1};
        dp[startRow][startColumn][0] = 1;
        ll ans = 0;
        for (int moves = 1; moves <= maxMove; moves++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int nxtX = i + dirX[k];
                        int nxtY = j + dirY[k];
                        if (nxtX < 0 || nxtY < 0 || nxtX >= m || nxtY >= n)
                        {
                            ans = (ans + dp[i][j][moves - 1]) % mod;
                        }
                        else
                        {
                            dp[nxtX][nxtY][moves] = (dp[nxtX][nxtY][moves] + dp[i][j][moves - 1]) % mod;
                        }
                    }
                }
            }
        }
        return ans;
    }
};