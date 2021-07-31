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

int cnt(string s1, string s2, string s3, string s4, string s)
{
    int ans = s1 == s;
    ans += (s2 == s);
    ans += (s3 == s);
    ans += (s4 == s);
    return ans;
}

void solve()
{
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int a = cnt(s1, s2, s3, s4, "H");
    int b = cnt(s1, s2, s3, s4, "2B");
    int c = cnt(s1, s2, s3, s4, "3B");
    int d = cnt(s1, s2, s3, s4, "HR");
    if (a == 1 && b == 1 && c == 1 && d == 1)
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
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}