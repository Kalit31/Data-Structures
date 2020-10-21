#include <bits/stdc++.h>
using namespace std;

//Type: Math
//Approach: Moore's Voting algorithm
//Complexity: O(N) time and O(1) space

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majEle = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (majEle == nums[i])
            {
                count++;
            }
            else
            {
                count--;
                if (count == 0)
                {
                    majEle = nums[i];
                    count = 1;
                }
            }
        }
        return majEle;
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int majorElement;

        for (int num : nums)
        {
            if (count == 0)
            {
                majorElement = num;
            }
            count += (num == majorElement) ? 1 : -1;
        }

        return majorElement;
    }
};

//Or use a map.