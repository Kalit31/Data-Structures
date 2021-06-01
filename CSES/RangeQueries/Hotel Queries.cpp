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

struct SegmentTree
{
    int n;
    vector<int> lo, hi;
    vector<int> vals, delta;
    vector<int> data;

    void init(int n, vector<int> x)
    {
        this->n = n;
        lo.clear();
        lo.resize(4 * n + 1);
        hi.clear();
        hi.resize(4 * n + 1);
        vals.clear();
        vals.resize(4 * n + 1, 0);
        delta.clear();
        delta.resize(4 * n + 1, 0);
        data = x;
        initializeNodes(1, 0, n - 1);
    }

    void initializeNodes(int i, int a, int b)
    {
        lo[i] = a;
        hi[i] = b;

        if (a == b)
        {
            vals[i] = data[a];
            return;
        }
        int mid = (a + b) / 2;
        initializeNodes(2 * i, a, mid);
        initializeNodes(2 * i + 1, mid + 1, b);
        updateHelper(i);
    }

    void update(int a, int b, int val)
    {
        updateNodes(1, a, b, val);
    }

    void propagate(int i)
    {
        delta[2 * i] += delta[i];
        delta[2 * i + 1] += delta[i];
        delta[i] = 0;
    }

    void updateHelper(int i)
    {
        vals[i] = max(vals[2 * i] + delta[2 * i], vals[2 * i + 1] + delta[2 * i + 1]);
    }

    void updateNodes(int i, int a, int b, int val)
    {
        // deb(i);
        if (lo[i] > b || hi[i] < a)
        {
            return;
        }
        //complete cover
        if (lo[i] >= a && b >= hi[i])
        {
            delta[i] += val;
            return;
        }

        //partial cover
        propagate(i); //push change to children
        updateNodes(2 * i, a, b, val);
        updateNodes(2 * i + 1, a, b, val);
        updateHelper(i);
    }

    int minimum(int a, int b)
    {
        return minimum(1, a, b);
    }

    int minimum(int i, int a, int b)
    {
        if (lo[i] > b || hi[i] < a)
        {
            return 0;
        }
        if (a <= lo[i] && hi[i] <= b)
        {
            return vals[i] + delta[i];
        }

        propagate(i);

        //do not update my min, bcoz minLeft and minRight may be partial covers of the subtrees

        int minLeft = minimum(2 * i, a, b);
        int minRight = minimum(2 * i + 1, a, b);

        updateHelper(i);

        int ans = max(minLeft, minRight);
        return ans;
    }
};

SegmentTree tree;

int findSolution(int r, vector<int> &h)
{
    int n = h.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int present = tree.minimum(0, mid);
        if (present >= r)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (ans != -1)
    {
        tree.update(ans, ans, -r);
    }
    return ans + 1;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    vector<int> r(m);
    for (int i = 0; i < m; i++)
    {
        cin >> r[i];
    }
    tree.init(n, h);
    for (int i = 0; i < m; i++)
    {
        cout << findSolution(r[i], h) << " ";
    }
    cout << endl;
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