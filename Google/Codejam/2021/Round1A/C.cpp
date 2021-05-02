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

int calcDigits(ll num)
{
    int digits = 0;
    while (num)
    {
        digits++;
        num /= 10;
    }
    return digits;
}

void solve()
{
    string s1 = "1234";
    string s2 = "1232";
    if (s1 > s2)
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }
    int n;
    cin >> n;
    vector<string> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int moves = 0;
    for (int i = 1; i < n; i++)
    {
        if (x[i].size() > x[i - 1].size())
        {
            continue;
        }
        else if (x[i].size() == x[i - 1].size())
        {
            bool poss = false;
            bool equal = true;

            for (int j = 0; j < x[i].size(); j++)
            {
                if (x[i][j] < x[i - 1][j])
                {
                    poss = true;
                    equal = false;
                }
                else if (x[i][j] > x[i - 1][j])
                {
                    equal = false;
                }
            }
            if (!poss && !equal)
                continue;
            moves++;
            x[i] += '0';
        }
        else
        {
            bool poss = false;
            bool equal = true;
            for (int j = 0; j < x[i].size(); j++)
            {
                if (x[i][j] < x[i - 1][j])
                {
                    poss = true;
                    equal = false;
                }
                else if (x[i][j] > x[i - 1][j])
                {
                    equal = false;
                }
            }
            if (poss)
            {
                int toAdd = x[i - 1].size() - x[i].size() + 1;
                string s(toAdd, '0');
                x[i] += s;
                moves += toAdd;
                continue;
            }
            if (!equal)
            {

                int toAdd = x[i - 1].size() - x[i].size();
                string s(toAdd, '0');
                x[i] += s;
                moves += toAdd;
                continue;
            }

            string add = "";
            bool greater = false;
            for (int j = x[i - 1].size() - 1; j >= x[i].size(); j--)
            {
                if (greater)
                {
                    add = x[i - 1][j] + add;
                }
                else if (x[i - 1][j] == '9')
                {
                    add = x[i - 1][j] + add;
                }
                else
                {
                    add = to_string(x[i - 1][j] - '0' + 1) + add;
                    greater = true;
                }
            }
            if (!greater)
            {
                //999 sort of
                int toAdd = x[i - 1].size() - x[i].size() + 1;
                string s(toAdd, '0');
                x[i] += s;
                moves += toAdd;
                continue;
            }
            x[i] += add;
            moves += add.size();
        }
    }
    cout << moves << endl;
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