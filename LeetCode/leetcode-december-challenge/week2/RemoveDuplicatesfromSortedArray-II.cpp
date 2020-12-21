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
    int removeDuplicates(vector<int> &nums)
    {
        int l = 1, i = 1, n = nums.size();
        if (!n)
            return 0;

        while (i < n)
        {
            if (nums[l - 1] != nums[i])
            {
                swap(nums[l++], nums[i]);
            }
            else if (i == 1 || nums[l - 1] != nums[l - 2])
            {
                swap(nums[l++], nums[i]);
            }
            ++i;
        }

        return l;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0 or nums.size() == 1)
            return nums.size();
        int l = 2;
        for (int r = 2; r < nums.size(); r++)
        {
            if (nums[l - 2] != nums[r])
            {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        bool occured = false;
        int last = nums[0];
        auto it = nums.begin();
        for (it++; it != nums.end(); it++)
        {
            if (*it == last)
            {
                if (!occured)
                {
                    occured = true;
                }
                else
                {
                    nums.erase(it);
                    it--;
                }
            }
            else
            {
                last = *it;
                occured = false;
            }
        }
        return nums.size();
    }
};