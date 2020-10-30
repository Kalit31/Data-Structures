#include <bits/stdc++.h>
using namespace std;

//Type: Math
//Approach:
//Complexity: O(1) time and O(N) space

class Solution
{
public:
    vector<int> arr;
    Solution(vector<int> &w)
    {
        arr.push_back(w[0]);
        for (int i = 1; i < w.size(); i++)
        {
            arr.push_back(arr.back() + w[i]);
        }
    }

    int pickIndex()
    {
        int randWeight = rand() % (arr.back());
        return upper_bound(arr.begin(), arr.end(), randWeight) - arr.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */