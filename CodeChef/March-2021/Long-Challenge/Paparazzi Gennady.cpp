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
    tc.n = randomNumber(1, 1000);
    tc.a.resize(tc.n);
    for (int i = 0; i < tc.n; i++)
    {
        tc.a[i] = randomNumber(1, 100000);
    }
    return tc;
}

//O(N^3)
void solve()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    ll maxDiff = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll xdiff = i - j;
            ll ydiff = h[i] - h[j];
            bool poss = true;
            for (int k = i + 1; k < j; k++)
            {
                ll a1 = ydiff * (k - j);
                ll a2 = xdiff * (h[k] - h[j]);
                if (a1 > a2)
                {
                    poss = false;
                    break;
                }
            }
            if (poss)
            {
                maxDiff = max(maxDiff, (ll)(j - i));
            }
        }
    }
    cout << maxDiff << endl;
}

//O(N^2)
void solveOptimized()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    ll maxDiff = 1;
    for (int i = 0; i < n - 1; i++)
    {
        double slope = (1.0 * (h[i + 1] - h[i]));
        for (int j = i + 2; j < n; j++)
        {
            double currSlope = (1.0 * (h[j] - h[i])) / (j - i);
            if (currSlope >= slope)
            {
                slope = currSlope;
                maxDiff = max(maxDiff, (ll)(j - i));
            }
        }
    }
    cout << maxDiff << endl;
}

int solveOptimizedStressTest(testcase tc)
{
    int n = tc.n;
    vector<ll> h = tc.a;
    ll maxDiff = 1;
    for (int i = 0; i < n - 1; i++)
    {
        double slope = (1.0 * (h[i + 1] - h[i]));
        for (int j = i + 2; j < n; j++)
        {
            double currSlope = (1.0 * (h[j] - h[i])) / (j - i);
            if (currSlope >= slope)
            {
                slope = currSlope;
                maxDiff = max(maxDiff, (ll)(j - i));
            }
        }
    }
    return maxDiff;
}

//O(N)
void solveOpt()
{
    int n;
    cin >> n;
    vector<array<ll, 2>> h(n);
    vector<array<ll, 2>> st;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i][0];
        h[i][1] = i;
    }
    ll maxDiff = 1;
    for (int i = 0; i < n; i++)
    {
        if (st.size() < 2)
        {
            st.push_back(h[i]);
        }
        else
        {
            while (st.size() >= 2)
            {
                //(1.0 * (st - h[i])) / (j - i)
                array<ll, 2> prev = st.back();
                array<ll, 2> prprev = st[st.size() - 2];
                array<ll, 2> curr = h[i];
                double slope1 = (1.0 * (prprev[0] - prev[0])) / (prprev[1] - prev[1]);
                double slope2 = (1.0 * (prev[0] - curr[0])) / (prev[1] - curr[1]);
                if (slope2 >= slope1)
                {
                    st.pop_back();
                }
                else
                {
                    break;
                }
            }
            maxDiff = max(maxDiff, h[i][1] - st.back()[1]);
            st.push_back(h[i]);
        }
    }
    cout << maxDiff << endl;
}

int solveOptStressTest(testcase tc)
{
    int n = tc.n;
    vector<ll> a = tc.a;
    vector<array<ll, 2>> h(n);
    vector<array<ll, 2>> st;
    for (int i = 0; i < n; i++)
    {
        h[i][0] = a[i];
        h[i][1] = i;
    }
    ll maxDiff = 1;
    for (int i = 0; i < n; i++)
    {
        if (st.size() < 2)
        {
            st.push_back(h[i]);
        }
        else
        {
            while (st.size() >= 2)
            {
                //(1.0 * (st - h[i])) / (j - i)
                array<ll, 2> prev = st.back();
                array<ll, 2> prprev = st[st.size() - 2];
                array<ll, 2> curr = h[i];
                double slope1 = (1.0 * (prprev[0] - prev[0])) / (prprev[1] - prev[1]);
                double slope2 = (1.0 * (prev[0] - curr[0])) / (prev[1] - curr[1]);
                if (slope2 >= slope1)
                {
                    st.pop_back();
                }
                else
                {
                    break;
                }
            }
            maxDiff = max(maxDiff, h[i][1] - st.back()[1]);
            st.push_back(h[i]);
        }
    }
    return maxDiff;
}

void stressTest(int i)
{
    testcase tc = generateTestCase();
    cout << i << " : ";
    int ans1 = solveOptimizedStressTest(tc);
    int ans2 = solveOptStressTest(tc);
    if (ans1 != ans2)
    {
        cout << ans1 << " :: " << ans2 << " ";
        cout << "INCORRECT" << endl;
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
        solveOpt();
    }
    // int i = 1;
    // while (true)
    // {
    //     stressTest(i++);
    //     if (i == 1000000)
    //     {
    //         i = 1;
    //     }
    // }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}