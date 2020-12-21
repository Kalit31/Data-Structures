#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int cnt = 0;
        int n = A.size();

        map<int, int> m1, m2;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m1[A[i] + B[j]]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m2[C[i] + D[j]]++;
            }
        }

        for (auto it = m1.begin(); it != m1.end(); it++)
        {
            if (m2.find(-(it->first)) != m2.end())
            {
                cnt += (it->second) * m2[-(it->first)];
            }
        }

        return cnt;
    }
};