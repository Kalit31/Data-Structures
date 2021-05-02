#include <bits/stdc++.h>
using namespace std;
#define ll long long int

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it
*/

void solve()
{
    int u;
    cin >> u;
    map<char, ll> freq;
    set<char> diff;
    ll q;
    string s;
    for (int i = 0; i < 10000; i++)
    {
        cin >> q;
        cin >> s;
        freq[s[0]]++;
        for (char ch : s)
        {
            diff.insert(ch);
        }
    }
    char zeroCh = '?';
    vector<pair<ll, char>> arr;
    for (char ch : diff)
    {
        if (freq[ch] == 0)
        {
            zeroCh = ch;
        }
        else
        {
            arr.emplace_back(freq[ch], ch);
        }
    }
    assert(arr.size() == 9);
    sort(arr.rbegin(), arr.rend());
    cout << zeroCh;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i].second;
    }
    cout << endl;
}

int main()
{
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