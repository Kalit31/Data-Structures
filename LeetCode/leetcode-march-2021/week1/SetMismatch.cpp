#include <bits/stdc++.h>
using namespace std;

// O(N) time and space
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        for (int x : nums)
        {
            cnt[x]++;
        }
        vector<int> ans(2);
        for (int i = 1; i <= n; i++)
        {
            if (cnt[i] == 2)
            {
                ans[0] = i;
            }
            else if (cnt[i] == 0)
            {
                ans[1] = i;
            }
        }
        return ans;
    }
};

//O(N) time and O(1) space using XORs
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int XOR = 0;
        int n = nums.size();
        for (int i = 1; i <= n; i++)
        {
            XOR = XOR ^ i;
        }
        for (int i = 0; i < n; i++)
        {
            XOR = XOR ^ nums[i];
        }
        int rightmostbit = XOR & ~(XOR - 1);
        int xor1 = 0;
        int xor0 = 0;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] & rightmostbit) != 0)
            {
                xor1 = xor1 ^ nums[i];
            }
            else
            {
                xor0 = xor0 ^ nums[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if ((i & rightmostbit) != 0)
            {
                xor1 = xor1 ^ i;
            }
            else
            {
                xor0 = xor0 ^ i;
            }
        }
        vector<int> ans = {xor1, xor0};
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == xor0)
            {
                swap(ans[0], ans[1]);
                break;
            }
        }
        return ans;
    }
};

// Another approach: Since the elements are from 1 to n, use the properties of
//                   indices.
