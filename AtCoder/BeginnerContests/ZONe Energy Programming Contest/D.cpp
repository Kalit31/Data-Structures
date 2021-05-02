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

void solve()
{
    string s;
    cin >> s;
    string t = "";
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            cnt = 1 - cnt;
        }
        else
        {
            if (cnt == 0)
            {
                t += s[i];
            }
            else
            {
                t.insert(t.begin(), s[i]);
            }
        }
    }
    if (cnt)
    {
        reverse(t.begin(), t.end());
    }

    stack<char> st;

    for (int i = 0; i < t.size(); i++)
    {
        if (st.empty())
        {
            st.push(t[i]);
        }
        else
        {
            if (st.top() == t[i])
            {
                while (!st.empty() && st.top() == t[i])
                {
                    st.pop();
                }
            }
            else
            {
                st.push(t[i]);
            }
        }
    }
    string result = "";
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
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