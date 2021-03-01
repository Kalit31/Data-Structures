#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] ^ arr[i];
        }
        vector<int> result;
        for (vector<int> q : queries)
        {
            result.push_back(pre[q[1] + 1] ^ pre[q[0]]);
        }

        return result;
    }
};