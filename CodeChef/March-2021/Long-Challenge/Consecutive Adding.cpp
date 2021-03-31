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

void solve()
{
    int r, c, x;
    cin >> r >> c >> x;
    vector<vector<int>> a(r, vector<int>(c));
    vector<vector<int>> b(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> b[i][j];
        }
    }
    if (r % 2 == 0)
    {
        int i = 0;
        int j = 0;
        bool moveRight = true;
        while (!(i == (r - 1) && j == 0))
        {
            if (moveRight)
            {
                if (j == c - 1)
                {
                    if (a[i][j] != b[i][j])
                    {
                        int toAdd = b[i][j] - a[i][j];
                        a[i][j] = b[i][j];
                        a[i + 1][j] += toAdd;
                    }
                    i++;
                    moveRight = false;
                }
                else if (a[i][j] != b[i][j])
                {
                    int toAdd = b[i][j] - a[i][j];
                    a[i][j] = b[i][j];
                    a[i][j + 1] += toAdd;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if (j == 0)
                {
                    if (a[i][j] != b[i][j])
                    {
                        int toAdd = b[i][j] - a[i][j];
                        a[i][j] = b[i][j];
                        a[i + 1][j] += toAdd;
                    }
                    i++;
                    moveRight = true;
                }
                else if (a[i][j] != b[i][j])
                {
                    int toAdd = b[i][j] - a[i][j];
                    a[i][j] = b[i][j];
                    a[i][j - 1] += toAdd;
                    j--;
                }
                else
                {
                    j--;
                }
            }
            // cout << "(" << i << "," << j << ")" << endl
            //      << flush;
        }
        // cout << "OUT: (" << i << "," << j << ")" << endl
        //      << flush;
        if (a[r - 1][0] != b[r - 1][0])
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    else
    {
        int i = 0;
        int j = 0;
        bool moveRight = true;
        while (!(i == (r - 1) && j == (c - 1)))
        {
            if (moveRight)
            {
                if (j == c - 1)
                {
                    if (a[i][j] != b[i][j])
                    {
                        int toAdd = b[i][j] - a[i][j];
                        a[i][j] = b[i][j];
                        a[i + 1][j] += toAdd;
                    }
                    i++;
                    moveRight = false;
                }
                else if (a[i][j] != b[i][j])
                {
                    int toAdd = b[i][j] - a[i][j];
                    a[i][j] = b[i][j];
                    a[i][j + 1] += toAdd;
                    j++;
                }
                else
                {
                    j++;
                }
            }
            else
            {
                if (j == 0)
                {
                    if (a[i][j] != b[i][j])
                    {
                        int toAdd = b[i][j] - a[i][j];
                        a[i][j] = b[i][j];
                        a[i + 1][j] += toAdd;
                    }
                    i++;
                    moveRight = true;
                }
                else if (a[i][j] != b[i][j])
                {
                    int toAdd = b[i][j] - a[i][j];
                    a[i][j] = b[i][j];
                    a[i][j - 1] += toAdd;
                    j--;
                }
                else
                {
                    j--;
                }
            }
            // cout << "(" << i << "," << j << ")" << endl
            //      << flush;
        }
        // cout << "OUT: (" << i << "," << j << ")" << endl
        //      << flush;
        if (a[r - 1][c - 1] != b[r - 1][c - 1])
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}

bool build(vector<vector<int>> &a, vector<vector<int>> &b, int row, int x)
{
    int r = a.size();
    int c = a[0].size();
    if (row == r)
    {
        return true;
    }
    for (int col = 0; col <= (c - x); col++)
    {
        int toAdd = b[row][col] - a[row][col];
        for (int j = col; j < col + x; j++)
        {
            a[row][j] += toAdd;
        }
    }
    for (int col = c - x + 1; col < c; col++)
    {
        if (row + x <= r)
        {
            int toAdd = b[row][col] - a[row][col];
            for (int i = row; i < row + x; i++)
            {
                a[i][col] += toAdd;
            }
        }
        else
        {
            if (a[row][col] != b[row][col])
            {
                return false;
            }
        }
    }
    return build(a, b, row + 1, x);
}

void solveOptimized()
{
    int r, c, x;
    cin >> r >> c >> x;
    vector<vector<int>> a(r, vector<int>(c));
    vector<vector<int>> b(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> b[i][j];
        }
    }
    if (build(a, b, 0, x))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
        solveOptimized();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}