#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Maps

//Approach: Maintain a map which will store the first index found for every unique sumTillNow.
//          Add a 1 to the sum on encountering a 1 and subtract a 1 on encountering a 0.
//          If the current sum is in the map, it means there exist a subarry from the staring index(0),
//          whose sum is equal to the current sum. So, the elements, between the current index
//          and the index where the current sum was found, would sum up to zero.
//          Then, we update the maximum length.
//Complexity: O(N) time , O(N) space complexity

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> m;
        m[0] = -1;
        int currSum = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i] == 1 ? 1 : -1;
            if (m.find(currSum) != m.end())
            {
                maxLen = max(maxLen, i - m[currSum]);
            }
            else
            {
                m[currSum] = i;
            }
        }
        return maxLen;
    }
};