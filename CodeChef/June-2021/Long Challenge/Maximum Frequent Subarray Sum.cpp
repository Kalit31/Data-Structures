#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it.
         Check if test cases are present or not
*/

void computeLPSArray(string pat, ll M, ll lps[])
{
    ll len = 0;
    ll i = 1;
    lps[0] = 0;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = len;
                i++;
            }
        }
    }
}

ll KMPSearch(string pat, string txt)
{
    ll M = pat.length();
    ll N = txt.length();

    ll lps[M];
    ll j = 0;

    computeLPSArray(pat, M, lps);

    ll i = 0;
    ll res = 0;
    ll next_i = 0;

    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            j = lps[j - 1];
            res++;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll val = 0;
    map<ll, ll> mp;

    //value compression
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = val++;
        }
    }

    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = a[i] + pref[i - 1];
    }

    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += 'a' + mp[a[i]];
    }

    ll ans = LONG_LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll currSum = pref[j] - (i > 0 ? pref[i - 1] : 0);
            string sub = s.substr(i, j - i + 1);
            ll cnt = KMPSearch(sub, s);
            ans = max(ans, currSum * cnt);
        }
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}