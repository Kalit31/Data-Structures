#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct myComp
    {
        bool operator()(pair<int, int> const &a, pair<int, int> const &b)
        {
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> result;
        if (nums.size() == 0)
        {
            return result;
        }
        else if (nums.size() == k)
        {
            return nums;
        }

        unordered_map<int, int> m;
        for (int n : nums)
        {
            m[n]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pq;

        for (pair<int, int> p : m)
        {
            pq.push(p);
        }
        for (int i = 0; i < k; i++)
        {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};

/*
sort( values.begin( ), values.end( ), [ ]( const MyStruct& lhs, const MyStruct& rhs )
{
   return lhs.key < rhs.key;
});
*/