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
    bool increasingTriplet(vector<int> &nums)
    {
        int n1 = INT_MAX, n2 = INT_MAX;
        for (auto num : nums)
        {
            if (num <= n1)
            {
                n1 = num;
            }
            else if (num <= n2)
            {
                n2 = num;
            }
            else
                return true;
        }
        return false;
    }
};

//Using LIS approach
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis(n, 1);
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i] && lis[j] + 1 > lis[i])
                    lis[i] = lis[j] + 1;

        for (int i = 0; i < n; i++)
        {
            if (lis[i] >= 3)
            {
                return true;
            }
        }
        return false;
    }
};