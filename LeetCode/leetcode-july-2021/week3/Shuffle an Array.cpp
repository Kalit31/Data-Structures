#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> orig;
    vector<int> curr;
    Solution(vector<int> &nums)
    {
        orig = nums;
        curr = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return orig;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        next_permutation(curr.begin(), curr.end());
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */