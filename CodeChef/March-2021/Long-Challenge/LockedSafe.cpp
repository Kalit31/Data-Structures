#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()

struct testcase
{
    int n;
    vector<ll> a;
};

int randomNumber(int a, int b)
{
    return a + (rand() % b);
}

testcase generateTestCase()
{
    testcase tc;
    tc.n = randomNumber(1, 10);
    tc.a.resize(tc.n);
    for (int i = 0; i < tc.n; i++)
    {
        int idx = randomNumber(0, 60);
        if (idx == 0)
        {
            tc.a[i] = 0ll;
        }
        else
        {
            tc.a[i] = 1ll << (idx - 1);
        }
    }
    return tc;
}

ll solveBrute(testcase tc)
{
    ll n;
    //cin >> n;
    n = tc.n;
    vector<ll> a = tc.a;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll t1 = a[i];
            ll t2 = a[i];
            ll m1 = a[i];
            for (int k = i + 1; k <= j; k++)
            {
                t1 = t1 | a[k];
                t2 = t2 & a[k];
                m1 = max(m1, a[k]);
            }
            t1 = t1 ^ t2;
            if (t1 >= m1)
            {
                ans++;
            }
        }
    }
    return ans;
}

void solveBruteX()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            ll t1 = a[i];
            ll t2 = a[i];
            ll m1 = a[i];
            for (int k = i + 1; k <= j; k++)
            {
                t1 = t1 | a[k];
                t2 = t2 & a[k];
                m1 = max(m1, a[k]);
            }
            t1 = t1 ^ t2;
            if (t1 >= m1)
            {
                ans++;
                cout << "TAKE: (" << i << "," << j << ")" << endl;
            }
            else
            {
                cout << "NOT TAKE: (" << i << "," << j << ")" << endl;
            }
        }
    }
    cout << ans << endl;
}
ll solve(testcase tc)
{
    ll n;
    n = tc.n;
    vector<ll> b = tc.a;
    vector<vector<int>> a(n, vector<int>(60, 0));
    vector<int> maxBit(n, -1);
    ll t;
    for (int i = 0; i < n; i++)
    {
        t = b[i];
        for (int j = 0; j < 60; j++)
        {
            if (t & (1ll << j))
            {
                a[i][j] = 1;
                maxBit[i] = j;
            }
        }
    }
    ll ans = (n * (n + 1)) / 2;
    int i = 1;
    ll cnt = 1;
    while (i < n)
    {
        if (maxBit[i - 1] == -1)
        {
            cnt = 1;
        }
        else
        {
            if (maxBit[i] == maxBit[i - 1])
            {
                cnt++;
            }
            else
            {
                ans -= (cnt * (cnt + 1)) / 2;
                cnt = 1;
            }
        }
        i++;
    }
    if (maxBit[i - 1] != -1)
        ans -= (cnt * (cnt + 1)) / 2;
    return ans;
}

void solveX()
{
    ll n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(60, 0));

    vector<int> maxBit(n, -1);
    ll t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        for (int j = 0; j < 60; j++)
        {
            if (t & (1ll << j))
            {
                a[i][j] = 1;
                maxBit[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << maxBit[i] << " ";
    }
    cout << endl;

    ll ans = (n * (n + 1)) / 2;
    int i = 1;
    ll cnt = 1;
    while (i < n)
    {
        if (maxBit[i - 1] == -1)
        {
            cnt = 1;
        }
        else
        {
            if (maxBit[i] == maxBit[i - 1])
            {
                cnt++;
            }
            else
            {
                ll rem = (cnt * (cnt + 1)) / 2;
                deb(rem);
                ans -= rem;
                cnt = 1;
            }
        }
        i++;
    }
    if (maxBit[i - 1] != -1)
    {
        ll rem = (cnt * (cnt + 1)) / 2;
        deb(rem);
        ans -= rem;
    }
    cout << ans << endl;
}

void printTC(testcase tc)
{
    cout << tc.n << endl;
    cout << flush;
    for (int i = 0; i < tc.n; i++)
    {
        cout << tc.a[i] << " " << flush;
    }
    cout << endl
         << flush;
}

void stressTest(int i)
{
    testcase tc = generateTestCase();
    cout << i << " : ";
    int ans1 = solveBrute(tc);
    int ans2 = solve(tc);
    if (ans1 != ans2)
    {
        cout << ans1 << " :: " << ans2 << " ";
        cout << "INCORRECT" << endl;
        printTC(tc);
        exit(1);
    }
    else
    {
        cout << endl;
    }
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        //     solveBrute();
        solveBruteX();
        solveX();
    }
    // int i = 1;
    // while (true)
    // {
    //     stressTest(i++);
    //     if (i == 1000000)
    //     {
    //         i = 1;
    //     }
    //     // break;
    // }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}