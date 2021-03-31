#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll my_pow(ll a, ll n, ll m = INF)
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

int H, W, A, B;
int ans = 0;

void dfs(int curr, int mask, int a, int b)
{
    if (curr == H * W)
    {
        ans++;
        return;
    }
    if (mask & (1 << curr))
    {
        //curr already visited
        dfs(curr + 1, mask, a, b);
    }
    if (b)
    {
        //place a 1x1 tile
        dfs(curr + 1, mask | (1 << curr), a, b - 1);
    }
    if (a)
    {
        int currPlusOneCellEmpty = (mask & (1 << (curr + 1))) == 0;
        if (curr % W != W - 1 && (currPlusOneCellEmpty))
        {
            //place a 2x1 tile horizontally
            dfs(curr + 1, mask | (1 << curr) | (1 << (curr + 1)), a - 1, b);
        }
        if (curr + W < H * W)
        {
            //place a 2x1 tile vertically
            dfs(curr + 1, mask | (1 << curr) | (1 << (curr + W)), a - 1, b);
        }
    }
}

void solve()
{
    cin >> H >> W >> A >> B;
    ans = 0;
    dfs(0, 0, A, B);
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}