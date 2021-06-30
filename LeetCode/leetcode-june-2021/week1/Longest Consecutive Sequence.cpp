#include <bits/stdc++.h>
using namespace std;

//O(n)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        unordered_set<int> s;
        for (int x : nums)
        {
            s.insert(x);
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            int curr = nums[i];
            //start of the the sequence
            if (s.find(curr - 1) == s.end())
            {
                int currAns = 1;
                while (s.find(curr + 1) != s.end())
                {
                    curr++;
                    currAns++;
                }
                ans = max(ans, currAns);
            }
        }
        return ans;
    }
};

//O(n lg n)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        set<int> s;
        for (int x : nums)
        {
            s.insert(x);
        }
        int ans = 1;
        int currAns = 1;
        int last = -1;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (it == s.begin())
            {
                last = *it;
                continue;
            }
            if (*it == last + 1)
            {
                currAns++;
            }
            else
            {
                ans = max(ans, currAns);
                currAns = 1;
            }
            last = *it;
        }
        ans = max(ans, currAns);
        return ans;
    }
};