// Write your code here
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll moves = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % 2 == 1)
            {
                if (i == (n - 1))
                {
                    moves += 2;
                }
                else
                {
                    if (a[i + 1] % 2 == 1)
                    {
                        moves++;
                    }
                    else
                    {
                        moves += 2;
                    }
                }
                i++;
            }
        }
        cout << moves << endl;
    }
}

//Another approach
int calc()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto &it : a)
            cin >> it;
        ll ans = 0, ok = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & 1)
            {
                ok++;
            }
            else
            {
                ans += (ok / 2) + 2 * (ok & 1);
                ok = 0;
            }
        }
        ans += (ok / 2) + 2 * (ok & 1);
        cout << ans << endl;
    }
    return 0;
}