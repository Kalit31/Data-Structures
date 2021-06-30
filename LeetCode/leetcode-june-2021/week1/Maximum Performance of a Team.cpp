#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution
{
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<array<int, 2>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = {speed[i], efficiency[i]};
        }
        auto comp = [&](const array<int, 2> &a, const array<int, 2> &b)
        {
            return a[1] < b[1];
        };
        sort(arr.begin(), arr.end(), comp);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll ans = 0;
        ll sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            pq.push(arr[i][0]);
            sum += arr[i][0];
            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, arr[i][1] * sum);
        }
        return ans % mod;
    }
};