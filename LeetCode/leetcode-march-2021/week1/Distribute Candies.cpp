#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        set<int> s;
        for (int candy : candyType)
        {
            s.insert(candy);
        }
        int n = candyType.size();
        n /= 2;
        int ans = min((int)(s.size()), n);
        return ans;
    }
};