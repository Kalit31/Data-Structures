#include <bits/stdc++.h>
using namespace std;

//O(N^2) soln. Fails: TLE :: N~10^5
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> a1(n + 1);
        a1[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            a1[i] = a1[i - 1] + nums[i - 1];
        }
        vector<int> a2(n + 1);
        a2[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            a2[i] = a2[i - 1] + nums[n - i];
        }
        int moves = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = n - i; j >= 0; j--)
            {
                if (a1[i] + a2[j] == x)
                {
                    moves = min(moves, i + j);
                }
            }
        }
        return moves == INT_MAX ? -1 : moves;
    }
};

//O(N lgN) soln.
// to find some prefix + suffix of the array = x
// Convert the problem to find the maximum length subarray(middle part)
// with sum = (totalsum - x)
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }
        if (totSum == x)
        {
            return n;
        }
        int toFind = totSum - x;
        map<int, int> m;
        m[0] = -1;
        int currSum = 0;
        int maxLen = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];
            if (m.find(currSum - toFind) != m.end())
            {
                maxLen = max(maxLen, i - m[currSum - toFind]);
            }
            m[currSum] = i;
        }
        return maxLen == INT_MIN ? -1 : n - maxLen;
    }
};