#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

void build(multiset<char> chars, set<string> &s, string t)
{
    if (chars.empty())
    {
        s.insert(t);
        return;
    }
    for (auto it = chars.begin(); it != chars.end(); it++)
    {
        multiset<char> tChars = chars;
        deb(*it);
        chars.erase(it);
        build(chars, s, t + *it);
        chars = tChars;
        deb(chars.size());
    }
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    sort(s.begin(), s.end());
    vector<string> result;
    do
    {
        result.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << result.size() << endl;
    for (string st : result)
    {
        cout << st << endl;
    }

    /* set<string> sList;
    multiset<char> chars;
    for (int i = 0; i < n; i++)
    {
        chars.insert(s[i]);
    }
    build(chars, sList, "");
    cout << sList.size() << endl;
    for (auto it = sList.begin(); it != sList.end(); it++)
    {
        cout << *it << endl;
    }*/
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    //cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}