#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reductionOperations(vector<int> &nums)
    {
        set<int, greater<int>> s;
        map<int, int> freq;
        for (int x : nums)
        {
            s.insert(x);
            freq[x]++;
        }
        int moves = 0;
        while (s.size() >= 2)
        {
            int largest = *(s.begin());
            s.erase(s.begin());
            int nLargest = *(s.begin());
            moves += freq[largest];
            freq[nLargest] += freq[largest];
        }
        return moves;
    }
};