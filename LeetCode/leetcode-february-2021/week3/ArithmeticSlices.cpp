#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &a, int l, int r)
    {
        int d = a[l + 1] - a[l];
        for (int i = l + 2; i <= r; i++)
        {
            if (a[i] - a[i - 1] != d)
            {
                return false;
            }
        }
        return true;
    }

    int numberOfArithmeticSlices(vector<int> &A)
    {
        int n = A.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 2; j < n; j++)
            {
                if (check(A, i, j))
                {
                    cnt++;
                }
                else
                {
                    break;
                }
            }
        }
        return cnt;
    }
};