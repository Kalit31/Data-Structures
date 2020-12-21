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
    int build(vector<int> &nums, int l, int r, map<pair<int, int>, int> &m)
    {
        if (l > r)
        {
            return 0;
        }
        if (m.find({l, r}) != m.end())
        {
            return m[{l, r}];
        }
        int score = 0;
        for (int i = l; i <= r; i++)
        {
            if (l == 0 && r == nums.size() - 1)
                score = max(score, nums[i] + build(nums, l, i - 1, m) + build(nums, i + 1, r, m));
            else if (l == 0)
                score = max(score, nums[i] * nums[r + 1] + build(nums, l, i - 1, m) + build(nums, i + 1, r, m));
            else if (r == nums.size() - 1)
                score = max(score, nums[i] * nums[l - 1] + build(nums, l, i - 1, m) + build(nums, i + 1, r, m));
            else
                score = max(score, nums[l - 1] * nums[i] * nums[r + 1] + build(nums, l, i - 1, m) + build(nums, i + 1, r, m));
        }
        m[{l, r}] = score;
        return score;
    }

    int maxCoins(vector<int> &nums)
    {
        map<pair<int, int>, int> m;
        return build(nums, 0, nums.size() - 1, m);
    }
};