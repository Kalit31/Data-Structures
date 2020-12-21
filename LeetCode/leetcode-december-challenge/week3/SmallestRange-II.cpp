#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestRangeII(vector<int> &A, int K)
    {
        int n = A.size();
        sort(A.begin(), A.end());
        int res = A[n - 1] - A[0];

        for (int i = 0; i < n - 1; i++)
        {
            int h = max(A[n - 1] - K, A[i] + K);
            int l = min(A[0] + K, A[i + 1] - K);
            res = min(res, h - l);
        }
        return res;
    }
};