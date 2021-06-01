#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 1000000006
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

void solve()
{
    int n;
    cin >> n;
    vector<array<ll, 2>> arr(n);
    ll num = 1;
    ll sum = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        num = (num * (arr[i][1] + 1)) % mod;
        ll currSum = my_pow(arr[i][0], arr[i][1] + 1, mod);
        currSum -= 1;
        currSum = (currSum + mod) % mod;
        currSum = (currSum * modInverse(arr[i][0] - 1)) % mod;
        sum = (sum * currSum) % mod;
    }

    ll prod = 1;
    ll cnt = 1;
    for (int i = 0; i < n; i++)
    {
        prod = (my_pow(prod, arr[i][1] + 1, mod) * my_pow(my_pow(arr[i][0], (arr[i][1] * (arr[i][1] + 1) / 2), mod), cnt, mod)) % mod;
        cnt = (cnt * (arr[i][1] + 1)) % mod2;
    }

    cout << num << " " << sum << " " << prod << endl;
}

/*
Do not why this is not working?
wrong logic1 oops :(
ll remainingNum = (num * modInverse(arr[i][1] + 1)) % mod;
ll times;
if (arr[i][1] % 2 == 0){
    ll tmp = arr[i][1] / 2;
    times = (tmp * (arr[i][1] + 1)) % mod2;
}else{
    ll tmp = (arr[i][1] + 1) / 2;
    times = (tmp * arr[i][1]) % mod2;
}
ll curr = my_pow(arr[i][0], times, mod);
curr = (curr * my_pow(remainingNum, arr[i][1] + 1, mod)) % mod;
prod = (prod * curr) % mod;

wrong logic2:
ll remainingNum = (num * modInverse(arr[i][1] + 1)) % mod;
ll times = (arr[i][1] * (arr[i][1] + 1));
times /= 2;
times = times % mod;
ll tmp = (times * remainingNum) % mod2;
ll curr = my_pow(arr[i][0], tmp, mod);
prod = (prod * curr) % mod;
*/

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