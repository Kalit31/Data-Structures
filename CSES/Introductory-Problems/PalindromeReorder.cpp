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
    int n = s.size();
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'A']++;
    }
    int oddCount = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] % 2)
        {
            oddCount++;
        }
    }
    if (oddCount > 1)
    {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (oddCount == 0)
    {
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                string t(freq[i] / 2, 'A' + i);
                freq[i] = freq[i] / 2;
                cout << t;
            }
        }
        for (int i = 25; i >= 0; i--)
        {
            if (freq[i] != 0)
            {
                string t(freq[i], 'A' + i);
                cout << t;
            }
        }
        cout << endl;
    }
    else
    {
        char oddCh;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2)
            {
                oddCh = 'A' + i;
                freq[i] = freq[i] - 1;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                string t(freq[i] / 2, 'A' + i);
                freq[i] = freq[i] / 2;
                cout << t;
            }
        }
        cout << oddCh;
        for (int i = 25; i >= 0; i--)
        {
            if (freq[i] != 0)
            {
                string t(freq[i], 'A' + i);
                cout << t;
            }
        }
        cout << endl;
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
    return 0;
}