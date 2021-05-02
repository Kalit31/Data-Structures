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

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

// check if a is a prefix of b
bool isPrefix(string a, string b)
{
    return a.size() <= b.size() && b.substr(0, a.size()) == a;
}

string incr(string s)
{
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != '9')
        {
            s[i]++;
            return s;
        }
        s[i] = '0';
    }
    return "1" + s;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int operations = 0;

    for (int i = 1; i < n; i++)
    {
        string &curr = x[i];
        string &prev = x[i - 1];
        int initalLen = curr.size();
        if (isPrefix(curr, prev))
        {
            if (isPrefix(curr, incr(prev)))
            {
                curr = incr(prev);
            }
            else
            {
                while (prev.size() >= curr.size())
                {
                    curr += '0';
                }
            }
        }
        else
        {
            while (curr.size() < prev.size() || (curr.size() == prev.size() && curr <= prev))
            {
                curr += '0';
            }
        }
        operations += curr.size() - initalLen;
    }
    cout << operations << endl;
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