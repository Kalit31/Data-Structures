// Write your code here
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int diffX = abs(x1 - x2);
    int diffY = abs(y1 - y2);
    if (diffX == 0 && diffY == 0)
    {
        cout << "SECOND" << endl;
    }
    else if ((diffX <= 1 && diffY <= 1))
    {
        cout << "FIRST" << endl;
    }
    else
    {
        cout << "DRAW" << endl;
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