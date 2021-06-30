#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve()
{
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        s.insert(p);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        //it points to the value >=(t+1)
        auto it = s.lower_bound(t + 1);

        if (it == s.begin())
        {
            cout << "-1" << endl;
        }
        else
        {
            //(it-1) would point to value <(t+1) OR <=t
            --it;
            cout << (*it) << endl;
            s.erase(it);
        }
    }
}

void solve2()
{
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        s.insert(p);
    }
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        //it points to the value >t
        auto it = s.upper_bound(t);

        if (it == s.begin())
        {
            cout << "-1" << endl;
        }
        else
        {
            //(it-1) would point to value <=t
            --it;
            cout << (*it) << endl;
            s.erase(it);
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
    // cin >> T;
    while (T--)
    {
        solve2();
    }
    return 0;
}