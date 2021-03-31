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

void solve()
{
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    int cost = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        int toFind = n + 1;
        int toFindInd = -1;
        for (int j = i; j < n; j++)
        {
            if (l[j] < toFind)
            {
                toFind = l[j];
                toFindInd = j;
            }
        }
        reverse(l.begin() + i, l.begin() + (toFindInd + 1));
        cost += toFindInd - (i) + 1;
    }
    cout << cost << endl;
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