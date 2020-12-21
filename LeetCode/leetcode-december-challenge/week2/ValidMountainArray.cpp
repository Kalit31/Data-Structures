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
    bool validMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
        {
            return false;
        }
        bool reachedPeak = false;
        for (int i = 1; i < n; i++)
        {
            if (!reachedPeak)
            {
                if (arr[i] < arr[i - 1])
                {
                    if (i == 1)
                    {
                        return false;
                    }
                    reachedPeak = true;
                }
                if (arr[i] == arr[i - 1])
                {
                    return false;
                }
            }
            else
            {
                if (arr[i] >= arr[i - 1])
                {
                    return false;
                }
            }
        }
        return reachedPeak;
    }
};