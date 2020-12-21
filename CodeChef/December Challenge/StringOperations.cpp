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
    string s;
    cin >> s;

    set<tuple<int, int, int>> eqS;

    for (int i = 0; i < s.length(); i++)
    {
        int cnt = 0;
        int odd = 0;
        int even = 0;
        for (int j = i; j < s.length(); j++)
        {
            if (s[j] == '1')
            {
                cnt++;
            }
            else
            {
                if (cnt % 2)
                {
                    odd++;
                }
                else
                {
                    even++;
                }
            }
            eqS.insert({j - i + 1, odd, even});
        }
    }
    cout << eqS.size() << endl;
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
        solve();
    }
    return 0;
}