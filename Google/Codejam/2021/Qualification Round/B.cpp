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
#define sq(x) ((x) * (x))

int findCost(string s, int x, int y)
{
    int cost = 0;
    int n = s.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == 'C' && s[i + 1] == 'J')
        {
            cost += x;
        }
        else if (s[i] == 'J' && s[i + 1] == 'C')
        {
            cost += y;
        }
    }
    return cost;
}

void solveBrute()
{
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ind;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            ind.push_back(i);
        }
    }

    int k = ind.size();
    // deb(k);
    int minCost = INT_MAX;
    for (int i = 0; i < (1 << k); i++)
    {
        string tmp = s;
        for (int j = 0; j < k; j++)
        {
            if (i & (1 << j))
            {
                tmp[ind[j]] = 'C';
            }
            else
            {
                tmp[ind[j]] = 'J';
            }
        }
        //deb(tmp);
        int currCost = findCost(tmp, x, y);
        //deb(currCost);
        minCost = min(minCost, currCost);
    }
    cout << minCost << endl;
}

void solveBrute2()
{
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?')
        {
            int left = i - 1;
            int j = i + 1;
            while (j < n && s[j] == '?')
            {
                j++;
            }
            if (left == -1 && j == n)
            {
                for (int k = 0; k < n; k++)
                {
                    s[k] = 'J';
                }
            }
            else if (left == -1)
            {
                for (int k = 0; k < j; k++)
                {
                    s[k] = s[j];
                }
            }
            else if (j == n)
            {
                for (int k = i; k < n; k++)
                {
                    s[k] = s[left];
                }
            }
            else
            {
                if (s[left] == s[j])
                {
                    for (int k = i; k < j; k++)
                    {
                        s[k] = s[left];
                    }
                }
                else
                {
                    for (int k = i; k < j; k++)
                    {
                        s[k] = 'C';
                    }
                }
            }
        }
    }
    int cost = findCost(s, x, y);
    cout << cost << endl;
}

void solve()
{
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.size();
    vector<ll> c(n, INT_MAX);
    vector<ll> j(n, INT_MAX);

    if (s[0] == 'C')
    {
        c[0] = 0;
    }
    else if (s[0] == 'J')
    {
        j[0] = 0;
    }
    else
    {
        c[0] = 0;
        j[0] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == '?')
        {
            c[i] = min(c[i - 1], j[i - 1] + y);
            j[i] = min(j[i - 1], c[i - 1] + x);
        }
        else if (s[i] == 'C')
        {
            //JC
            //CC
            c[i] = min(c[i - 1], j[i - 1] + y);
        }
        else
        {
            //CJ
            //JJ
            j[i] = min(j[i - 1], c[i - 1] + x);
        }
    }

    cout << min(c[n - 1], j[n - 1]) << endl;
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
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}