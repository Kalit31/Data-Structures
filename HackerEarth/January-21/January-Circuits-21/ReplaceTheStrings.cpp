#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '?')
            freq[s[i] - 'a']++;
        if (t[i] != '?')
            freq[t[i] - 'a']--;
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (abs(freq[i]) > 1)
        {
            cout << "NO" << endl;
            return;
        }
        else if (abs(freq[i]) == 1)
        {
            cnt++;
        }
    }
    if (cnt > 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}