#include <bits/stdc++.h>
using namespace std;

class FindSumPairs
{
public:
    map<int, int> mp;
    vector<int> arr;
    vector<int> arr2;
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        arr = nums1;
        arr2 = nums2;
        for (int x : nums2)
        {
            mp[x]++;
        }
    }

    void add(int index, int val)
    {
        mp[arr2[index]]--;
        arr2[index] += val;
        mp[arr2[index]]++;
    }

    int count(int tot)
    {
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            cnt += mp[tot - arr[i]];
        }

        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */