#include <bits/stdc++.h>
using namespace std;

//O(N lg N) greedy solution
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        vector<int> lis(n, 1);
        auto comp = [](const vector<int> &p1, const vector<int> &p2) -> bool {
            return p1[1] < p2[1];
        };
        sort(pairs.begin(), pairs.end(), comp);

        int ans = 1;
        int end = pairs[0][1];
        for (int i = 1; i < n; i++)
        {
            if (end < pairs[i][0])
            {
                ans++;
                end = pairs[i][1];
            }
        }
        return ans;
    }
};

//O(N^2) LIS soln
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        vector<int> lis(n, 1);
        auto comp = [](const vector<int> &p1, const vector<int> &p2) -> bool {
            return p1[1] < p2[1];
        };
        sort(pairs.begin(), pairs.end(), comp);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (pairs[i][0] > pairs[j][1] && lis[j] + 1 > lis[i])
                {
                    lis[i] = 1 + lis[j];
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
};