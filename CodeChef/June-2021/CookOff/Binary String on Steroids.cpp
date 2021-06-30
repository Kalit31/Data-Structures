#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it.
         Check if test cases are present or not
*/

int findFlips(string &s, int d, int &ones)
{
    int n = s.size();
    int ans = INT_MAX;
    //deb(d);
    for (int start = 0; start < d; start++)
    {
        int currAns = 0;
        int remOnes = ones;
        for (int i = start; i < n; i += d)
        {
            if (s[i] == '1')
            {
                remOnes--;
            }
            else
            {
                currAns++;
            }
        }
        currAns += remOnes;
        //deb(currAns);
        ans = min(ans, currAns);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ones++;
        }
    }
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int div1 = i;
            ans = min(ans, findFlips(s, div1, ones));
            int div2 = n / i;
            if (div1 != div2)
            {
                ans = min(ans, findFlips(s, div2, ones));
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}
