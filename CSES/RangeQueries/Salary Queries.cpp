#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

//Policy based data structures
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

void solve()
{
    int n, q;
    cin >> n >> q;
    ordered_set s;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        s.insert({p[i], i});
    }

    char op;
    while (q--)
    {
        cin >> op;
        if (op == '!')
        {
            int k, x;
            cin >> k >> x;
            s.erase({p[k], k});
            p[k] = x;
            s.insert({p[k], k});
        }
        else
        {
            int a, b;
            cin >> a >> b;
            int lessThanB = s.order_of_key({b, n + 1});
            int lessThanA = s.order_of_key({a, 0});
            cout << lessThanB - lessThanA << endl;
        }
    }
}

int main()
{
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