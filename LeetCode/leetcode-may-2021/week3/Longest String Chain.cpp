#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPredecessor(string &s1, string &s2)
    {
        int n = s1.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int cnt = 0;
        while (ptr1 < n)
        {
            if (s1[ptr1] == s2[ptr2])
            {
                ptr1++;
                ptr2++;
            }
            else
            {
                cnt++;
                ptr2++;
            }
            if (cnt > 1)
            {
                return false;
            }
        }
        return true;
    }

    int longestStrChain(vector<string> &words)
    {
        int maxLen = 1;

        vector<vector<string>> arr(17, vector<string>());
        vector<vector<int>> dp(17, vector<int>());

        for (int i = 0; i < words.size(); i++)
        {
            int wordLen = words[i].size();
            arr[wordLen].push_back(words[i]);
            dp[wordLen].push_back(1);
        }

        for (int i = 1; i < 16; i++)
        {
            if (dp[i].size() == 0 || dp[i + 1].size() == 0)
            {
                continue;
            }
            for (int j = 0; j < arr[i].size(); j++)
            {
                for (int k = 0; k < arr[i + 1].size(); k++)
                {
                    if (isPredecessor(arr[i][j], arr[i + 1][k]))
                    {
                        dp[i + 1][k] = max(dp[i + 1][k], 1 + dp[i][j]);
                        maxLen = max(maxLen, dp[i + 1][k]);
                    }
                }
            }
        }

        return maxLen;
    }
};