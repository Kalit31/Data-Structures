#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> solve(string &s, int start, unordered_set<string> &words, unordered_map<int, vector<string>> &dp)
    {
        if (dp.find(start) != dp.end())
        {
            return dp[start];
        }
        vector<string> result;
        if (start == s.size())
        {
            result.push_back("");
        }
        for (int i = start + 1; i <= s.size(); i++)
        {
            string sub = s.substr(start, i - start);
            if (words.find(sub) != words.end())
            {
                vector<string> res2 = solve(s, i, words, dp);
                for (string s : res2)
                {
                    result.push_back(sub + ((s == "") ? "" : " ") + s);
                }
            }
        }
        dp[start] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<int, vector<string>> dp;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return solve(s, 0, words, dp);
    }
};