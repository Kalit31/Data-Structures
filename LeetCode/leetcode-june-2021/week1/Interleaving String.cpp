#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[105][105];

    bool build(string &s1, string &s2, string &s3, int i, int j)
    {
        int n = s1.size();
        int m = s2.size();

        int ind = i + j;

        if (n + m == ind)
        {
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int curr = 0;
        while (i + curr < n)
        {
            if (s1[i + curr] == s3[ind + curr])
            {
                if (build(s1, s2, s3, i + curr + 1, j))
                {
                    return dp[i][j] = 1;
                }
            }
            else
            {
                break;
            }
            curr++;
        }
        curr = 0;
        while (j + curr < m)
        {
            if (s2[j + curr] == s3[ind + curr])
            {
                if (build(s1, s2, s3, i, j + curr + 1))
                {
                    return dp[i][j] = 1;
                }
            }
            else
            {
                break;
            }
            curr++;
        }
        return dp[i][j] = 0;
    }

    bool isInterleave(string s1, string s2, string s3)
    {
        memset(dp, -1, sizeof(dp));

        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        return build(s1, s2, s3, 0, 0);
    }
};