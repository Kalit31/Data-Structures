#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

// Policy based data structure
typedef tree<int, null_type,
             less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    Ordered_set;

// Function to find and return the
// median of every window of size k
void findMedian()
{

    Ordered_set s;

    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++)
        s.insert(arr[i]);

    int ans = *s.find_by_order((k - 1) / 2);

    cout << ans << " ";

    for (int i = 0; i < n - k; i++)
    {

        // Erasing Element out of window.
        s.erase(s.find_by_order(
            s.order_of_key(
                arr[i])));

        // Inserting newer element
        // to the window
        s.insert(arr[i + k]);

        ans = *s.find_by_order((k - 1) / 2);

        cout << ans << " ";
    }
    cout << endl;
}

void solve()
{
    findMedian();
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}