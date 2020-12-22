#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

void solve()
{
    ll n;
    cin >> n;
    vector<array<int, 3>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
        arr[i][2] = i;
    }

    sort(arr.begin(), arr.end());
    set<array<int, 2>> s;
    vector<int> allocation(n);
    for (int i = 0; i < n; i++)
    {
        auto it = s.lower_bound({arr[i][0]});
        if (it != s.begin())
        {
            --it;
            allocation[arr[i][2]] = (*it)[1];
            s.erase(it);
        }
        else
        {
            allocation[arr[i][2]] = s.size();
        }
        s.insert({arr[i][1], allocation[arr[i][2]]});
    }
    cout << s.size() << endl;
    for (int i = 0; i < n; i++)
    {
        cout << allocation[i] + 1 << " ";
    }
    cout << endl;
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
        solve();
    }
    return 0;
}