#include <bits/stdc++.h>
using namespace std;

//Simple recursive + memoized fails due to stack overflow
//Iterative fails giving TLE
//Apply some observations

class Solution
{
public:
    int build(unordered_map<int, int> &m, int n)
    {
        if (n <= 1)
        {
            return n;
        }
        if (m.find(n) != m.end())
        {
            return m[n];
        }
        int way = 1 + min(n % 3 + build(m, n / 3), n % 2 + build(m, n / 2));
        m[n] = way;
        return way;
    }

    int minDays(int n)
    {
        // vector<int> dp(n+1,0);
        // dp[0] = 0;
        // dp[1] = 1;
        // for(int i=2;i<=n;i++){
        //     dp[i] = 1+dp[i-1];
        //     if(i%2==0){
        //         dp[i] = min(dp[i],1+dp[i/2]);
        //     }
        //     if(i%3==0){
        //         dp[i] = min(dp[i],1+dp[i/3]);
        //     }
        // }
        unordered_map<int, int> m;
        return build(m, n);
    }
};
