#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int sum = 0;
        int longestSubarray = 0;
        unordered_map<int, int> mapVal;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 1 ? 1 : -1;

            if (sum == 0)
            {
                if (longestSubarray < i + 1)
                {
                    longestSubarray = i + 1;
                }
            }
            else if (mapVal.count(sum))
            {
                if (longestSubarray < i - mapVal[sum])
                {
                    longestSubarray = i - mapVal[sum];
                }
            }
            else
            {
                mapVal[sum] = i;
            }
        }
        return longestSubarray;
    }
};

class Solution
{
public:
    int findMaxLength(vector<int> arr)
    {
        int sum = 0, maxlen = 0, n = arr.size();
        vector<int> idx(2 * n + 1, -1);
        for (int i = 0; i < n; i++)
        {
            sum += arr[i] == 1 ? 1 : -1;
            if (sum == 0)
            {
                maxlen = i + 1;
                continue;
            }
            if (idx[sum + n] == -1)
                idx[sum + n] = i;
            else
                maxlen = max(maxlen, i - idx[sum + n]);
        }
        return maxlen;
    }
};