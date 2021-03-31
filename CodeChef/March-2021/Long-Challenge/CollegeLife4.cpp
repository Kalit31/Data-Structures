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

ll power(ll a, ll n, ll m = INF)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

struct testcase
{
    int n, e, h, a, b, c;
};

int randomNumber(int a, int b)
{
    return a + (rand() % b);
}

testcase generateTestCase()
{
    testcase tc;
    tc.n = randomNumber(1, 1000000);
    tc.e = randomNumber(1, 1000000);
    tc.h = randomNumber(1, 1000000);
    tc.a = randomNumber(1, 100);
    tc.b = randomNumber(1, 100);
    tc.c = randomNumber(1, 100);
    return tc;
}

// omelette : a : 2 eggs
// chocolate milkshake : b : 3 chocolate bars
// chocolate cake : c : 1 egg + 1 chocolate bars
void solveBrute()
{
    int n, e, h, a, b, c;
    cin >> n >> e >> h >> a >> b >> c;
    int cost = INT_MAX;

    for (int o = 0; o <= n; o++)
    {
        for (int cm = 0; cm <= n && n - o - cm >= 0; cm++)
        {
            int eggs = n + o - cm;
            int chocbars = n + 2 * cm - o;
            if (eggs >= 0 && eggs <= e && chocbars >= 0 && chocbars <= h)
            {
                int currCost = o * (a - c) + cm * (b - c) + n * c;
                if (currCost < cost)
                {
                    cost = currCost;
                }
            }
        }
    }
    if (cost == INT_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << cost << endl;
}

ll calc(ll itemsNeeded, ll omelletes, ll shakes, ll cakes, ll a, ll b, ll c)
{
    vector<array<ll, 2>> arr;
    arr.push_back({a, omelletes});
    arr.push_back({b, shakes});
    arr.push_back({c, cakes});
    sort(arr.begin(), arr.end());

    ll cost = 0;

    ll item = min(itemsNeeded, arr[0][1]);
    cost += item * arr[0][0];
    itemsNeeded -= item;
    item = min(itemsNeeded, arr[1][1]);
    cost += item * arr[1][0];
    itemsNeeded -= item;
    item = min(itemsNeeded, arr[2][1]);
    cost += item * arr[2][0];
    itemsNeeded -= item;
    if (itemsNeeded != 0)
    {
        return LONG_LONG_MAX;
    }
    return cost;
}

void solveOptimized()
{
    ll n, e, h, a, b, c;
    cin >> n >> e >> h >> a >> b >> c;
    ll tE = e;
    ll tH = h;
    ll maxItems = min(e, h);
    e -= maxItems;
    h -= maxItems;
    maxItems += e / 2 + h / 3;
    if (maxItems < n)
    {
        cout << -1 << endl;
        return;
    }
    e = tE;
    h = tH;
    ll maxCakes = min(e, h);
    ll cost = LONG_LONG_MAX;
    for (ll cakes = 0; cakes <= min(maxCakes, n); cakes++)
    {
        ll leftEggs = e - cakes;
        ll leftCB = h - cakes;
        ll omelletesPoss = leftEggs / 2;
        ll shakesPoss = leftCB / 3;
        cost = min(cost, calc(n, omelletesPoss, shakesPoss, cakes, a, b, c));
    }
    if (cost == LONG_LONG_MAX)
    {
        cout << -1 << endl;
        return;
    }
    cout << cost << endl;
}

void printTC(testcase tc)
{
    cout << tc.n << " " << tc.e << " " << tc.h << " " << tc.a << " " << tc.b << " " << tc.c << " -- ";
    cout << flush;
}

void stressTest(int i)
{
    testcase tc = generateTestCase();
    cout << i << " : ";
    printTC(tc);
    //int ans1 = solveBrute(tc);
    //int ans2 = solveOptimized(tc);
    // if (ans1 != ans2)
    // {
    //     cout << ans1 << " :: " << ans2 << " ";
    //     cout << "INCORRECT" << endl;
    //     exit(1);
    // }
    // else
    // {
    //     cout << endl;
    //     //cout << "CORRECT" << endl;
    // }
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
        solveOptimized();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}