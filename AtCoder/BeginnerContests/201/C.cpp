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

set<int> must;
set<int> may;
set<int> no;

bool isValid(int num, string s)
{
    string numS = to_string(num);
    vector<int> cnt(10, 0);
    if (numS.size() < 4)
    {
        cnt[0]++;
    }
    for (int i = 0; i < numS.size(); i++)
    {
        cnt[numS[i] - '0']++;
    }
    for (int x : must)
    {
        if (cnt[x] == 0)
        {
            return false;
        }
    }
    for (int x : no)
    {
        if (cnt[x] != 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'o')
        {
            must.insert(i);
        }
        else if (s[i] == '?')
        {
            may.insert(i);
        }
        else
        {
            no.insert(i);
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 9999; i++)
    {
        if (isValid(i, s))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
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