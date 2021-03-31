#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*
EDITORIAL 

Let n be the number of digits of N.

We use the following Dynamic Programming (DP).
dp[i][j]: The number of combination of the most significant i digits such that 
1. strictly less than the most significant i digits of N, 
2. not all digits are 0, 
3. there are j distinct digits, except for the leading 0s.

From dp[i][j], we have the following transitions:

If we use any of j digits used so far for the i+1-th significant digit:     
    add dp[i][j]×j to dp[i+1][j] 
If we use a digit other than j digits used so far for the i+1-th significant digit: 
    add dp[i][j]×(16−j) to dp[i+1][j+1]
    
By the definition of dp[i][j], we know that it is already strictly less than N,
so no matter what digit we choose, the most significant i+1 digits we obtain is less than 
the most significant i+1 digits of N.

Also, other than them, we have to process those which is not contained in dp[i] 
but affects dp[i+1].

If the most significant N digits is equal to those of N,
    The most significant i+1 digits should be less than the most significant 
    i+1 digits of N
    Since the most significant i digits is equal to those of N, 
    it is easy to find the set of the digits used so far, 
    and therefore we can find the number of combinations of the i+1 digits after transition.

If the first i digits are all 0
    That is, the i+1-th digit is the first appearance of non-zero digit
    Since the most significant digit of N is non-zero, the resulting i+1 digits is 
    always less than the most significant i+1 digits of N, no matter which of 15
    kinds of digits is used for the i+1-th digit
    Therefore, we can add 15 to dp[i+1][1]

dp[n][K] is the number of those integers less than N
that satisfies the conditions given in the problem statement,
so if we additionally process those which are equal to N, we can easily find the answer.

With a proper implementation, the time complexity is O(nd)=O(log(N)d), where 
    d is the radix (=16 in this problem).

*/

// Code By: hitonanode

int c2i(char c)
{
    if (isdigit(c))
        return c - '0';
    else
        return c - 'A' + 10;
}

void solve()
{
    string s;
    int k;
    cin >> s >> k;
    int upper_mask = 0;
    vector<ll> dp(17, 0);
    bool init = true;
    for (auto c : s)
    {
        //extract ith digit from left(most siginificant bit)
        int d = c2i(c);
        vector<ll> dpnxt(dp.size(), 0);
        for (int i = 0; i < dp.size(); i++)
        {

            dpnxt[i] = (dpnxt[i] + dp[i] * i) % mod;
            if (i + 1 < dpnxt.size())
                dpnxt[i + 1] = (dpnxt[i + 1] + dp[i] * (16 - i)) % mod;
        }

        for (int e = 0; e < 16; e++)
        {
            if (e < d)
            {
                if (init and e == 0)
                    continue;
                int ind = __builtin_popcount(upper_mask | (1 << e));
                // deb(ind);
                dpnxt[ind] = (dpnxt[ind] + 1) % mod;
            }
        }

        if (!init)
        {
            dpnxt[1] = (dpnxt[1] + 15) % mod;
        }

        init = false;
        upper_mask |= 1 << d;
        deb(upper_mask);
        dp = dpnxt;
    }
    dp[__builtin_popcount(upper_mask)] += 1;
    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << dp[k] << '\n';
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}