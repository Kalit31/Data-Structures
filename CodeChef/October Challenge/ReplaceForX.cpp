#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void solve(vector<ll> A, ll N, ll X, ll p, ll k)
{
    sort(A.begin(), A.end());
    ll operations = 0;

    if (A[p] == X)
    {
        cout << operations << endl;
        return;
    }

    if (N == 1)
    {
        cout << 1 << endl;
        return;
    }

    if (p == k)
    {
        if (X > A[p])
        {
            int i = p;
            while (i < N)
            {
                if (A[i] >= X)
                {
                    break;
                }
                operations++;
                i++;
            }
        }
        else
        {
            int i = p;
            while (i >= 0)
            {
                if (A[i] <= X)
                {
                    break;
                }
                operations++;
                i--;
            }
        }
    }
    else if (p < k)
    {
        if (A[p] < X)
        {
            cout << "-1" << endl;
            return;
        }
        ll i = p;
        while (i >= 0)
        {
            if (A[i] <= X)
            {
                break;
            }
            operations++;
            i--;
        }
    }
    else
    {
        if (A[p] > X)
        {
            cout << "-1" << endl;
            return;
        }
        ll i = p;
        while (i < N)
        {
            if (A[i] >= X)
            {
                break;
            }
            operations++;
            i++;
        }
    }

    cout << operations << endl;
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
        ll N, X, p, k;
        cin >> N >> X >> p >> k;
        vector<ll> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        solve(A, N, X, p - 1, k - 1);
    }
    return 0;
}