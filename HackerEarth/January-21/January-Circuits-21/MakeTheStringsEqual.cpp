#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    int moves = 0;
    int i = 0;
    while (true)
    {
        i = 0;
        for (; i < n - 1; i++)
        {
            if (s[i + 1] < s[i])
            {
                swap(s[i + 1], s[i]);
                moves++;
                break;
            }
        }
        if (i == (n - 1))
        {
            break;
        }
    }

    while (true)
    {
        i = 0;
        for (; i < n - 1; i++)
        {
            if (t[i + 1] < t[i])
            {
                swap(t[i + 1], t[i]);
                moves++;
                break;
            }
        }
        if (i == (n - 1))
        {
            break;
        }
    }
    if (moves % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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