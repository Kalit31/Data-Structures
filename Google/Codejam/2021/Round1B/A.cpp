#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

const ll t = 120000000000;

bool tryToFind(ll h, ll m, ll s)
{
    if (s % t != 0)
    {
        return false;
    }
    ll secs = s / t;
    if (secs % 6 != 0)
    {
        return false;
    }
    secs /= 6;
    if (secs < 0 || secs >= 60)
    {
        return false;
    }
    double min = 1.0 * m / t;
    double minutes = (min - (secs / 10.0));
    if (floor(minutes) != minutes)
    {
        return false;
    }
    minutes = (ll)floor(minutes);
    if (minutes < 0 || (ll)minutes % 6 != 0)
    {
        return false;
    }
    minutes /= 6;
    if (minutes < 0 || minutes >= 60)
    {
        return false;
    }
    double hr = 1.0 * h / t;
    double hour = (hr - (minutes / 2.0) - (secs / 120.0));
    if (floor(hour) != hour)
    {
        return false;
    }
    hour = (ll)floor(hour);
    if (hour < 0 || (ll)hour % 30 != 0)
    {
        return false;
    }
    hour /= 30;
    if (hour < 0 || hour >= 12)
    {
        return false;
    }
    cout << hour << " " << minutes << " " << secs << " " << 0 << endl;
    return true;
}

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;

    //tryToFind(a, b, c);
    if (tryToFind(a, b, c))
    {
    }
    else if (tryToFind(a, c, b))
    {
    }
    else if (tryToFind(b, c, a))
    {
    }
    else if (tryToFind(b, a, c))
    {
    }
    else if (tryToFind(c, b, a))
    {
    }
    else if (tryToFind(c, a, b))
    {
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
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}