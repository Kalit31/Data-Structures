#include <bits/stdc++.h>
using namespace std;

//O(N^2) solution similar to longest increasing subsequence
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n == 0)
        {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end());
        vector<int> lis(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((envelopes[i][0] > envelopes[j][0]) &&
                    (envelopes[i][1] > envelopes[j][1]) &&
                    lis[i] < lis[j] + 1)
                {
                    lis[i] = lis[j] + 1;
                }
            }
        }

        return *max_element(lis.begin(), lis.end());
    }
};

//O(N lg N) solution
class Solution
{
public:
    struct custComp
    {
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            if (a[0] == b[0])
            {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        }
    };

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n == 0)
        {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), custComp());

        vector<int> dp(n, 0);
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int r = maxLen;
            while (l < r)
            {
                int m = l + (r - l) / 2;
                if (dp[m] < envelopes[i][1])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            dp[l] = envelopes[i][1];
            if (l == maxLen)
            {
                maxLen++;
            }
        }
        return maxLen;
    }
};