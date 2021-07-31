#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({abs(arr[i] - x), arr[i]});
        }
        vector<int> result;
        while (k--)
        {
            auto curr = pq.top();
            pq.pop();
            result.push_back(curr[1]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        if (n == k)
        {
            return arr;
        }
        int lo = 0;
        int hi = n - 1;
        int mid = 0;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (arr[mid] > x)
            {
                hi = mid - 1;
            }
            else if (arr[mid] < x)
            {
                lo = mid + 1;
            }
            else
            {
                break;
            }
        }
        lo = max(0, mid - 1);
        hi = lo + 1;
        //cout<<lo<<" - "<<hi<<endl;
        while (hi - lo - 1 < k)
        {
            if (lo == -1)
            {
                hi++;
                continue;
            }
            if (hi == n)
            {
                lo--;
                continue;
            }
            int val1 = arr[hi] - x;
            int val2 = x - arr[lo];
            if (val1 < val2)
            {
                hi++;
            }
            else
            {
                lo--;
            }
        }
        vector<int> result;
        for (int i = lo + 1; i < hi; i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
};