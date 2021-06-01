#include <bits/stdc++.h>
using namespace std;

//Two Pointer O(N) time and O(1) space
class Solution
{
public:
    int atmostS(vector<int> &nums, int S)
    {
        if (S < 0)
        {
            return 0;
        }
        int cnt = 0;
        int n = nums.size();
        int ptr1 = 0;
        int ptr2 = 0;
        int sum = 0;

        while (ptr2 < n)
        {
            sum += nums[ptr2];
            while (sum > S)
            {
                sum -= nums[ptr1++];
            }
            cnt += ptr2 - ptr1 + 1;
            ptr2++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int ans = atmostS(A, S) - atmostS(A, S - 1);
        return ans;
    }
};

//Hash maps O(N) time and O(N) space
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0;
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            currSum += A[i];
            if (mp.find(currSum - S) != mp.end())
            {
                ans += mp[currSum - S];
            }
            mp[currSum]++;
        }
        return ans;
    }
};