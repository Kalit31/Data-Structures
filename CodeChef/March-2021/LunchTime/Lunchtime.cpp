#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

// O(N^2) solution
// should not work, but passed in contest
void solve()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int ht = h[i];
        int j = i - 1;
        int cnt = 0;
        while (j >= 0 && h[j] <= ht)
        {
            if (h[j] == ht)
            {
                cnt++;
            }
            j--;
        }
        j = i + 1;
        while (j < n && h[j] <= ht)
        {
            if (h[j] == ht)
            {
                cnt++;
            }
            j++;
        }
        ans[i] = cnt;
    }
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
}

// Another approach, O(N) using stacks
void solveOpt()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<int> ans(n);

    stack<array<int, 2>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top()[0] < h[i])
        {
            st.pop();
        }
        if (st.empty() || st.top()[0] != h[i])
        {
            st.push({h[i], 0});
        }
        ans[i] += st.top()[1];
        st.top()[1]++;
    }
    while (!st.empty())
    {
        st.pop();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top()[0] < h[i])
        {
            st.pop();
        }
        if (st.empty() || st.top()[0] != h[i])
        {
            st.push({h[i], 0});
        }
        ans[i] += st.top()[1];
        st.top()[1]++;
    }

    for (int x : ans)
    {
        cout << x << " ";
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
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}