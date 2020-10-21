#include <bits/stdc++.h>
using namespace std;

//Type: Arrays, Maths

//Approach: An element at index i in the result would contain
//          the product of all the values to the left of i and to the right of i.
//          We start out by traversing the array from left to right,
//          storing the product of all elements before it.
//          Now, to store the product of all the elements to the right,
//          we would need an extra array, otherwise we would corrupt our result array data.
//          To do it in constant space, we maintain a temporary variable and start traversing right to left,
//          storing all the product of right elements.
//          Then, we simply multiply this temp with the result for each index.
//Complexity: O(N) time , O(1) space complexity

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size());
        result[0] = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            result[i] = result[i - 1] * nums[i - 1];
        }
        int temp = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            temp = temp * nums[i + 1];
            result[i] = result[i] * temp;
        }
        return result;
    }
};