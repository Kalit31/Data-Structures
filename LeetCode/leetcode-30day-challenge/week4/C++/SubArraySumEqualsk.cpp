#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Maps

//Approach: Maintain a map to store all the frequencies of unique sums
//          till now. Now, saya t a current index i, the totalSum of elements
//          is S. So, we will have to find out whether a sum of (S-k) occured
//          previously. If yes, add the number of times we found it.
//          Increment the count of current sum in the map.
//Complexity: O(N) time and O(N) space

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        int count = 0;
        int sum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
            if (sumMap.count(sum - k))
            {
                count += sumMap[sum - k];
            }
            sumMap[sum] = sumMap[sum] + 1;
        }
        return count;
    }
};