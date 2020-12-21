#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool check(vector<int> t, int k)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < t.size(); i++)
    {
        sum += t[i];
        if (sum > 0)
        {
            count++;
        }
    }
    if (count == k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solveBrute()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    for (int i = 0; i < pow(2, n); i++)
    {
        vector<int> t = a;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) == 0)
            {
                t[j] = -t[j];
            }
        }

        if (check(t, k))
        {
            for (int j = 0; j < n; j++)
            {
                cout << t[j] << " ";
            }
            cout << endl;
            return;
        }
    }
}

int calc(vector<int> &a)
{
    int n = a.size();
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > 0)
        {
            count++;
        }
    }
    return count;
}

void printArray(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    ll sum = 0;

    if (n % 2)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2)
            {
                a[i] = i;
            }
            else
            {
                a[i] = -i;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                a[i] = i;
            }
            else
            {
                a[i] = -i;
            }
        }
    }
    ll count = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (sum > 0)
        {
            count++;
        }
    }
    if (count < k)
    {
        for (int i = n; count != k && i > 0; i--)
        {
            if (a[i] < 0)
            {
                a[i] = -a[i];
                count++;
            }
        }
    }
    else if (count > k)
    {
        for (int i = n; count != k && i > 0; i--)
        {
            if (a[i] > 0)
            {
                a[i] = -a[i];
                count--;
            }
        }
    }
    printArray(a);
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
        solve();
    }
    return 0;
}