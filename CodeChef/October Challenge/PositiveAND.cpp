#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
//#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

//Type: Math, Bit Manipulation
//Approach : The key idea to observe here is, a number which is power of 2,
//          would always result a '0' upon ANDing with numbers less than it.
//          So, if n = power of 2, no permutation is possible.
//          For other cases, we know that a number which is power of 2, would
//          result a '0' upon ANDing with its predecessor.
//          So, if we swap this number(power of 2) with its successor, things would be sorted.
//          Predecessor                    : 011...........1   <----
//          NUM(pow of 2) be represented as: 100...........0       |=> Could be ANDed resulting a non-zero num.
//          Successor                      : 100...........1   <----
//          Do handle the base conditions for n=1 and n=3.
// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool isPowerOfTwo(ll n)
{
    while (n % 2 == 0)
    {
        n /= 2;
    }
    if (n == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(ll n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (isPowerOfTwo(n))
    {
        cout << "-1" << endl;
        return;
    }
    vector<ll> res(n + 1);
    for (int i = 1; i <= n; i++)
    {
        res[i] = i;
    }
    res[1] = 2;
    res[2] = 3;
    res[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        if (isPowerOfTwo(i))
        {
            swap(res[i], res[i + 1]);
            i++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return;
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
        ll n;
        cin >> n;
        solve(n);
    }
    return 0;
}