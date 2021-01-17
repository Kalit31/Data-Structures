// Write your code here
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        set<ll, greater<ll>> coins;
        ll coin;
        for (ll i = 0; i < n; i++)
        {
            cin >> coin;
            coins.insert(coin);
        }
        ll profit = 0;
        while (!coins.empty() && k > 0)
        {
            auto it = coins.begin();
            profit += *it;
            coins.erase(*it);
            k--;
        }
        cout << profit << endl;
    }
}
