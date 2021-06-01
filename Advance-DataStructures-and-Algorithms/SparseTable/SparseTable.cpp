#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1 << 20);
const int MAXLOG = 20;

struct SparseTable
{
    int dp[MAXLOG][MAXN];
    int lg2[MAXN], n, P;

    void init(vector<int> &a)
    {
        memset(dp, 0, sizeof(dp));
        memset(lg2, 0, sizeof(lg2));
        n = a.size();
        P = (int)(log(n) / log(2));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = a[i];
        }

        for (int i = 2; i <= n; i++)
        {
            lg2[i] = lg2[i / 2] + 1;
        }

        for (int i = 1; i <= P; i++)
        {
            for (int j = 0; j + (1 << i) <= n; j++)
            {
                int l = dp[i - 1][j];
                int r = dp[i - 1][j + (1 << (i - 1))];
                dp[i][j] = min(l, r);
            }
        }
    }

    int minQuery(int l, int r)
    {
        int len = r - l + 1;
        int p = lg2[len];
        int lVal = dp[p][l];
        int rVal = dp[p][r - (1 << p) + 1];
        return min(lVal, rVal);
    }
};

SparseTable sparseTable;

/*
    Some bugs in the below code
*/

// struct SparseTable
// {
//     int dp[MAXLOG][MAXN];
//     int idx[MAXLOG][MAXN];
//     int lg2[MAXN], n, P;

//     SparseTable()
//     {
//         memset(dp, 0, sizeof(dp));
//         memset(lg2, 0, sizeof(lg2));
//         n = 0;
//     }

//     void init(vector<int> &a)
//     {
//         n = a.size();
//         P = (int)(log(n) / log(2));
//         for (int i = 0; i < n; i++)
//         {
//             dp[0][i] = a[i];
//             idx[0][i] = i;
//         }

//         for (int i = 2; i <= n; i++)
//         {
//             lg2[i] = lg2[i / 2] + 1;
//         }

//         for (int i = 1; i <= P; i++)
//         {
//             for (int j = 0; j + (1 << i) <= n; i++)
//             {
//                 int l = dp[i - 1][j];
//                 int r = dp[i - 1][j + (1 << (i - 1))];
//                 dp[i][j] = min(l, r);
//                 // Above code works for range min queries
//                 if (l <= r)
//                 {
//                     idx[i][j] = idx[i - 1][j];
//                 }
//                 else
//                 {
//                     idx[i][j] = idx[i - 1][j + (1 << (i - 1))];
//                 }
//             }
//         }
//     }

//     int minQuery(int l, int r)
//     {
//         int len = r - l + 1;
//         int p = lg2[len];
//         int l = dp[p][l];
//         int r = dp[p][r - (1 << p) + 1];
//         return min(l, r);
//     }

//     int minQueryIdx(int l, int r)
//     {
//         int len = r - l + 1;
//         int p = lg2[len];
//         int l = dp[p][l];
//         int r = dp[p][r - (1 << p) + 1];
//         if (l <= r)
//         {
//             return idx[p][l];
//         }
//         else
//         {
//             return idx[p][r - (1 << p) + 1];
//         }
//     }

//     int sumQuery(int l, int r)
//     {
//         int sum = 0;
//         for (int p = lg2[r - l + 1]; l <= r; p = lg2[r - l + 1])
//         {
//             sum += dp[p][l];
//             l += (1 << p);
//         }
//         return sum;
//     }
// };