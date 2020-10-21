#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Algorithms

//Approach: Kadane's algorithm
//          Start with current max sum and sumtillnow with the first element of the array
//          Now, check which one is bigger sumtillnow + current element or the current element
//          The above condition basically means, whether we have to take include the current element
//          in the sum or else start over by intializing sum with current element.
//          Update the sumtillnow
//          check the maximum among the current max sum and sumtillnow and update it.
//          This code handles all the possible cases of positive and negative array elements.
//Complexity: O(N) time and O(1) space

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        int currMax = nums[0];
        int sumTillNow = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sumTillNow = max(sumTillNow + nums[i], nums[i]);
            currMax = max(currMax, sumTillNow);
        }
        return currMax;
    }
};