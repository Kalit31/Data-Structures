#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"

const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

int maxPower(int a1, int a2, int a3)
{
    return max(a1, max(a2, a3));
}

int strength(array<int, 5> &p1, array<int, 5> &p2, array<int, 5> &p3)
{
    int a = maxPower(p1[0], p2[0], p3[0]);
    int b = maxPower(p1[1], p2[1], p3[1]);
    int c = maxPower(p1[2], p2[2], p3[2]);
    int d = maxPower(p1[3], p2[3], p3[3]);
    int e = maxPower(p1[4], p2[4], p3[4]);
    return min(a, min(b, min(c, min(d, e))));
}

void solve()
{
    int n;
    cin >> n;
    vector<array<int, 5>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                ans = max(ans, strength(arr[i], arr[j], arr[k]));
            }
        }
    }
    cout << ans << endl;
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
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}