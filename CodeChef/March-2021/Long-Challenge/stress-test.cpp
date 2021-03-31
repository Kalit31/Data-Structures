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

ll my_pow(ll a, ll n, ll m = INF)
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
    tc.n = randomNumber(1, 100);
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
int solveBrute(testcase tc)
{
    int n, e, h, a, b, c;
    //cin >> n >> e >> h >> a >> b >> c;
    n = tc.n;
    e = tc.e;
    h = tc.h;
    a = tc.a;
    b = tc.b;
    c = tc.c;
    int cost = INT_MAX;

    for (int o = 0; o <= n && o <= (e / 2); o++)
    {
        for (int cm = 0; cm <= n && cm <= (h / 3); cm++)
        {
            if (n - o - cm < 0)
            {
                continue;
            }
            int eggs = n + o - cm;
            int chocbars = n + 2 * cm - o;
            if (eggs >= 0 && eggs <= e && chocbars >= 0 && chocbars <= h)
            {
                int currCost = o * (a - c) + cm * (b - c) + n * c;
                cost = min(cost, currCost);
            }
        }
    }
    if (cost == INT_MAX)
    {
        return -1;
    }
    return cost;
}

int n, e, h, a, b, c;
int cost = 0;
int total = 0;

void solveB();
void solveC();

void solveA()
{
    //  int total = 0;
    //choose maximum possible omelletes first
    int omelletes = min(n - total, e / 2);
    total += omelletes;
    cost += omelletes * a;
    e -= omelletes * 2;
    if (total == n)
    {
        return;
    }

    if (b < c)
    {
        //choose maximum possible chocolate milkshakes first
        // a<b<c
        if (h / 3 > 0)
            solveB();
        else
            solveC();
    }
    else
    {
        //choose maximum possible chocolate cakes first
        // a<c<b
        if (min(e, h) > 0)
            solveC();
        else
            solveB();
    }
}

void solveB()
{
    //choose maximum possible chocolate milkshakes first
    int cm = min(n - total, h / 3);
    total += cm;
    cost += cm * b;
    h -= cm * 3;
    if (total == n)
    {
        return;
    }

    if (a < c)
    {
        //choose maximum possible omelletes first
        // b<a<c
        if (e / 2 > 0)
            solveA();
        else
            solveC();
    }
    else
    {
        //choose maximum possible chocolate cakes first
        // b<c<a
        if (min(e, h) > 0)
            solveC();
        else
            solveA();
    }
}

void solveC()
{
    //choose maximum possible chocolate cakes first
    int cc = min(n - total, min(e, h));
    total += cc;
    cost += cc * c;
    h -= cc;
    e -= cc;
    // cout << "H: " << h << endl
    //      << flush;
    // cout << "E: " << e << endl
    //      << flush;
    if (total == n)
    {
        return;
    }

    if (a < b)
    {
        //choose maximum possible omelletes first
        // c<a<b
        if (e / 2 > 0)
            solveA();
        else
        {
            //  cout << "CALLED C" << flush;
            solveB();
        }
    }
    else
    {
        //choose maximum possible chocolate milkshakes first
        // c<b<a
        if (h / 3 > 0)
            solveB();
        else
            solveA();
    }
}

int calc(int itemsNeeded, int omelletes, int shakes, int cakes, int a, int b, int c)
{
    vector<array<int, 2>> arr;
    arr.push_back({a, omelletes});
    arr.push_back({b, shakes});
    arr.push_back({c, cakes});
    sort(arr.begin(), arr.end());

    int cost = 0;

    int item = min(itemsNeeded, arr[0][1]);
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
        return INT_MAX;
    }
    return cost;
}

int solveOptimized(testcase tc)
{
    //cin >> n >> e >> h >> a >> b >> c;
    n = tc.n;
    e = tc.e;
    h = tc.h;
    a = tc.a;
    b = tc.b;
    c = tc.c;
    int tE = e;
    int tH = h;
    int maxItems = min(e, h);
    e -= maxItems;
    h -= maxItems;
    maxItems += e / 2 + h / 3;
    if (maxItems < n)
    {
        return -1;
    }
    e = tE;
    h = tH;
    int maxCakes = min(e, h);
    int cost = INT_MAX;
    for (int cakes = 0; cakes <= min(maxCakes, n); cakes++)
    {
        int leftEggs = e - cakes;
        int leftCB = h - cakes;
        int omelletesPoss = leftEggs / 2;
        int shakesPoss = leftCB / 3;
        cost = min(cost, calc(n, omelletesPoss, shakesPoss, cakes, a, b, c));
    }
    if (cost == INT_MAX)
    {
        return -1;
    }
    return cost;
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
    int ans1 = solveBrute(tc);
    int ans2 = solveOptimized(tc);
    if (ans1 != ans2)
    {
        cout << ans1 << " :: " << ans2 << " ";
        cout << "INCORRECT" << endl;
        exit(1);
    }
    else
    {
        cout << endl;
        //cout << "CORRECT" << endl;
    }
}

int main()
{
    fast;
    // #ifndef ONLINE_JUDGE
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    //     freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
    // #endif
    // int T = 1;
    // cin >> T;
    // while (T--)
    // {
    //     solveOptimized();
    // }
    int i = 1;
    while (true)
    {
        stressTest(i++);
        if (i == 1000000)
        {
            i = 1;
        }
        // break;
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}