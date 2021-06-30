#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool poss(string &s, string &p, vector<int> &removable, int k)
    {
        int n = s.size();
        int m = p.size();
        vector<bool> removed(n, false);
        for (int i = 0; i < k; i++)
        {
            removed[removable[i]] = true;
        }
        int i = 0;
        int j = 0;

        while (i < n && j < m)
        {
            if (removed[i])
            {
                i++;
            }
            else if (s[i] == p[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }

        return j == m;
    }

    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int n = removable.size();
        int lo = 0;
        int hi = n;
        int ans = 0;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (poss(s, p, removable, mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};