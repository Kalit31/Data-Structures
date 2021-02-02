#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string a, string b)
    {
        int ans = INT_MAX;
        for (int j = 1; j < 5; j++)
        {
            int cnt = 0;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] - 'a' >= j)
                {
                    cnt++;
                }
            }
            for (int i = 0; i < b.size(); i++)
            {
                if (b[i] - 'a' < j)
                {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }
        return ans;
    }

    int minCharacters(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        int minMoves = INT_MAX;

        //cond1
        minMoves = min(minMoves, solve(a, b));

        //cond2
        minMoves = min(minMoves, solve(b, a));

        //cout<<minMoves<<endl;
        //cond3
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for (int i = 0; i < n; i++)
        {
            freq1[a[i] - 'a']++;
        }
        for (int i = 0; i < m; i++)
        {
            freq2[b[i] - 'a']++;
        }
        int moves = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq1[i] == 0)
            {
                continue;
            }
            int curr = n - freq1[i] + m - freq2[i];
            moves = min(curr, moves);
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq2[i] == 0)
            {
                continue;
            }
            int curr = n - freq1[i] + m - freq2[i];
            moves = min(curr, moves);
        }
        minMoves = min(minMoves, moves);
        return minMoves;
    }
};