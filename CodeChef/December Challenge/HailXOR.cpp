#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solveTest()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    int bitMtx[n][32];
    memset(bitMtx, 0, sizeof(bitMtx));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ll mask = 1;
        for (int j = 0; j < 32; j++)
        {
            if ((a[i] & mask) != 0)
            {
                bitMtx[i][31 - j] = 1;
            }
            mask = mask * 2;
            //deb(mask);
        }
    }
    int ind = 0;
    while (x > 0)
    {
        int msb = 0;
        for (; msb < 32; msb++)
        {
            if (bitMtx[ind][msb] == 1)
            {
                bitMtx[ind][msb] = 0;
                break;
            }
        }
        //a[ind] has become 0
        if (msb == 32)
        {
            ind++;
            if (ind >= (n - 1))
            {
                break;
            }
            else
            {
                continue;
            }
        }
        int i = ind + 1;
        if (ind == (n - 3) && x % 2 == 0)
            i++;
        /*if (x % 2 == 0)
        {
            i++;
        }*/
        for (; i < n; i++)
        {
            if (bitMtx[i][msb] == 1)
            {
                bitMtx[i][msb] = 0;
                x--;
                break;
            }
        }
        if (i == n)
        {
            bitMtx[n - 1][msb] = 1;
            x--;
        }
    }

    if (x != 0)
    {
        if (x % 2)
        {
            bitMtx[n - 2][31] = 1;
            bitMtx[n - 1][31] = 1 - bitMtx[n - 1][31];
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll num = 0;
        ll mask = 1;
        for (int j = 31; j >= 0; j--)
        {
            if (bitMtx[i][j] == 1)
            {
                num += mask;
            }
            mask = mask * (ll)2;
        }
        cout << num << " ";
    }
    cout << endl;
}

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ind = 0;

    while (x > 0 && ind < n - 1)
    {
        ll p = (log(a[ind]) / log(2));
        ll powP = pow(2, p);
        a[ind] = a[ind] ^ (powP);
        int j = ind + 1;
        for (; j < n; j++)
        {
            if ((a[j] ^ powP) < a[j])
            {
                break;
            }
        }
        //  deb(j);
        if (j == n)
            j--;
        a[j] = a[j] ^ powP;
        x--;
        if (a[ind] == 0)
            ind++;
    }
    if (x % 2 && n == 2)
    {
        a[0] = a[0] ^ 1;
        a[1] = a[1] ^ 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int p = (log(4) / log(2));
    //deb(p);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}