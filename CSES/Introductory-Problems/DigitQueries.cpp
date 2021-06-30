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
//const ll NEGINF = -1 * INF;
const ll N = 1e6 + 1;

vector<ll> a;

void pre()
{
    ll limit = 1e18;
    ll currSum = 0;
    ll i = 1;
    ll j = 9;
    while (currSum <= limit)
    {
        currSum += i * j;
        a.push_back(currSum);
        i++;
        j = j * 10;
    }
}

void solve()
{
    pre();

    ll q;
    cin >> q;
    ll k;
    while (q--)
    {
        cin >> k;
        auto it = lower_bound(a.begin(), a.end(), k);
        ll idx = distance(a.begin(), it);
        if (idx == 0)
        {
            cout << k << endl;
        }
        else
        {
            ll more = k - a[idx - 1];
            ll digitsInEachNum = (idx + 1);
            ll x = (more - 1) / digitsInEachNum;
            ll y = more % digitsInEachNum;
            if (y == 0)
                y = digitsInEachNum;
            y = digitsInEachNum - y;
            ll start = pow(10, idx);
            start += x;
            while (y)
            {
                start /= 10;
                y--;
            }
            cout << start % 10 << endl;
        }
    }
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
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}