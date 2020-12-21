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
    int kthFactor(int n, int k)
    {
        int curr = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                curr++;
                if (curr == k)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};