#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;
#define REP(i, n) for (int i = 1; i <= n; i++)

ll arr[3];
ll I[3][3];
ll T[3][3];

void multiply(ll A[3][3], ll B[3][3], int dim)
{
    ll temp[dim + 1][dim + 1];
    REP(i, dim)
    REP(j, dim)
    {
        temp[i][j] = 0;
        REP(k, dim)
        {
            temp[i][j] += (A[i][k] * B[k][j]) % mod;
        }
    }
    REP(i, dim)
    REP(j, dim)
    A[i][j] = temp[i][j];
}

ll getFib(ll n)
{
    if (n <= 2)
    {
        return arr[n];
    }
    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;

    T[1][1] = 0;
    T[1][2] = T[2][1] = T[2][2] = 1;

    n--;

    while (n)
    {
        if (n % 2)
        {
            multiply(I, T, 2);
            n--;
        }
        multiply(T, T, 2);
        n = n / 2;
    }
    ll result = (arr[1] * I[1][1] + arr[2] * I[2][1]) % mod;
    return result;
}

void solve()
{
    ll n;
    cin >> n;
    arr[1] = 0;
    arr[2] = 1;
    cout << getFib(n + 1) << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}