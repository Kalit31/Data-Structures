#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    ll minNum = 1;

    vector<int> notPrimes;
    for (int i = 0; i < n; i++)
    {
        bool isPrime = false;
        for (int j = 0; j < primes.size(); j++)
        {
            if (a[i] == primes[j])
            {
                minNum *= a[i];
                isPrime = true;
                break;
            }
        }
        if (!isPrime)
        {
            notPrimes.push_back(a[i]);
        }
    }

    ll num = 1;
    for (int i = 1; i <= 50; i++)
    {
        bool poss = true;
        for (int j = 0; j < notPrimes.size(); j++)
        {
            if (gcd(notPrimes[j], i) == 1)
            {
                if (gcd(notPrimes[j], minNum) == 1)
                {
                    poss = false;
                    break;
                }
            }
        }
        if (poss)
        {
            num = i;
            break;
        }
    }
    minNum = (minNum * num) / gcd(minNum, num);
    cout << minNum << endl;
}

void solve2()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    ll minNum = LONG_LONG_MAX;

    for (int i = 1; i < (1 << primes.size()); i++)
    {
        ll prime = 1;
        for (int j = 0; j < primes.size(); j++)
        {
            if (i & (1 << j))
            {
                prime *= primes[j];
            }
        }
        // deb(prime);
        bool poss = true;
        for (int i = 0; i < n; i++)
        {
            if (gcd(a[i], prime) == 1)
            {
                poss = false;
                break;
            }
        }
        if (poss)
        {
            minNum = min(minNum, prime);
        }
    }

    cout << minNum << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve2();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}