#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    vector<int> arr;
    int l;
    int r;
    RecentCounter()
    {
        arr.clear();
        l = 0;
        r = 0;
    }

    int ping(int t)
    {
        arr.push_back(t);
        while (l < r && arr[r] - arr[l] > 3000)
        {
            l++;
        }
        int ans = r - l + 1;
        r++;
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */