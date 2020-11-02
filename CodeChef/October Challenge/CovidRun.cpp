#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
//#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

//Type: Math, Arrays
//Approach: We maintain a map for all the cities which are currently infected.
//          Start from the city X and keep iterating untill,
//          1. The current city is city Y.
//          2. The current city is already been infected. Thus, no need
//             to iterate further, as we will be traversing the same cities again.
//Complexity: O(N) time and space

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

bool check(int n, int k, int x, int y)
{
    unordered_map<int, bool> m;
    m[x] = true;
    while (true)
    {
        int next = (x + k) % n;
        if (next == y)
        {
            return true;
        }
        if (m[next])
        {
            return false;
        }
        m[next] = true;
        x = next;
    }
    return false;
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
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        if (check(n, k, x, y))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}