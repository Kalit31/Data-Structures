#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const int N = 1e6 + 5;

ll my_pow(ll a, ll n, ll m)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

ll modInverse(ll num)
{
    return my_pow(num, mod - 2, mod);
}

/*
Idea: 
suppose n = 8
=>  1   2   3   4   5   6   7   8
    ------------------------------
    1   1   1   1   1   1   1   1
        2   3   2   5   2   7   2
                4       3       4
                        6       8
    ------------------------------
sum:1   3   4   7   6   12  8   15 = 56

number of times 1 occurs: 8
                2 occurs: 4
                3 occurs: 2
                4 occurs: 2
                5 occurs: 1
                6 occurs: 1
                7 occurs: 1
                8 occurs: 1

sum = summation(i from 1 to n) (n/i)*i

for i <= sqrt(n)
    (n/i) >= sqrt(n)

for sqrt(n)<i<n
    (n/i) lies between [1, sqrt(n)]

    now, we need to find the range for a particular (n/i) value

    considering the above example:
        the divisors 3 and 4 occur 1 times each: (3+4)*2
        the divisors 5,6,7 and 8 occur 2 times each: (5+6+7+8)*1

    so, we maintain a left and right pointer. 
    This range contains the divisors with the same occurence
    To fins the sum of this range, [l+1,r] we use: [1....r]-[1....l]
        = (r*(r+1))/2 - (l*(l+1))/2
*/

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        ans = (ans + ((n / i) * i) % mod) % mod;
    }
    ll l = sqrt(n);
    for (ll i = sqrt(n); i >= 1; i--)
    {
        ll r = n / i;
        ll currSum = 0;
        currSum += (((r % mod) * ((r + 1) % mod)) % mod * modInverse(2)) % mod;
        currSum = currSum % mod;
        currSum -= (((l % mod) * ((l + 1) % mod)) % mod * modInverse(2)) % mod;
        currSum = (currSum + mod) % mod;
        currSum = (currSum * i) % mod;
        l = r;
        ans = (ans + currSum) % mod;
    }
    cout << ans << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}