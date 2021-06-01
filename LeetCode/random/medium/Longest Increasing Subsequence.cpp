#include <bits/stdc++.h>
using namespace std;

//Longest increasing subsequence
//O(N lg N) solution

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> arr;
        arr.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr.back() < nums[i])
            {
                arr.push_back(nums[i]);
            }
            else
            {
                int idx = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
                arr[idx] = nums[i];
            }
        }
        return arr.size();
    }
};

//O(N lg N) manual binary search
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            int l = 0;
            int r = maxLen;
            while (l < r)
            {
                int m = l + (r - l) / 2;
                if (dp[m] < nums[i])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            dp[l] = nums[i];
            if (l == maxLen)
            {
                maxLen++;
            }
        }
        return maxLen;
    }
};

//O(N^2) solution
int lis(const vector<int> &A)
{
    int n = A.size();
    int lI[n];
    lI[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lI[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && lI[i] < lI[j] + 1)
            {
                lI[i] = lI[j] + 1;
            }
        }
    }
    return *max_element(lI, lI + n);
}