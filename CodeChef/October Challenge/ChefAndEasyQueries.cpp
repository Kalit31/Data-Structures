#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
//#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

//Type: Math
//Approach: Maintain a variable leftOver which keeps the count of queries to be answered.
//          If on a day i, the queries are more than k, we add the remaining queries to leftOver.
//          If the queries are less than k, we find the out the queries which could be answered today
//          taking account of the remaining queries. Also, update the leftOver queries.

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve(vector<ll> &queries, ll n, ll k)
{
    ll leftOver = 0;
    for (int i = 0; i < n; i++)
    {
        if (queries[i] >= k)
        {
            leftOver += queries[i] - k;
        }
        else
        {
            int answerToday = queries[i] + leftOver;
            if (answerToday < k)
            {
                cout << (i + 1) << endl;
                return;
            }
            leftOver = max((ll)0, leftOver - (k - queries[i]));
        }
    }
    n = n + (ll)(leftOver / k) + 1;
    cout << n << endl;
    return;
}

int main()
{
    fast;

#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> queries(n);
        for (int i = 0; i < n; i++)
        {
            cin >> queries[i];
        }
        solve(queries, n, k);
    }

    return 0;
}