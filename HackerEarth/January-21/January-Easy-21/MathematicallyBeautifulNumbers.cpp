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
        ll x, k;
        cin >> x >> k;
        bool poss = true;
        while (x != 1)
        {
            while (x % k == 0)
            {
                x /= k;
            }
            if (x == 1)
            {
                break;
            }
            if (x % k != 0)
            {
                x--;
            }
            if (x == 1)
            {
                break;
            }
            if (x % k != 0)
            {
                poss = false;
                break;
            }
        }
        if (poss)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

//Another approach
int m[40], t;
void calc()
{
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 40; i++)
            m[i] = 0;
        long long int x;
        int k, cnt = 0;
        cin >> x >> k;
        while (x)
        {
            cnt++;
            m[x % k]++;
            x /= k;
        }
        if (m[0] + m[1] == cnt)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}