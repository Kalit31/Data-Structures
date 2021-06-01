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
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c - 1));
    vector<vector<int>> b(r - 1, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c - 1; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r - 1; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> b[i][j];
        }
    }
    vector<vector<vector<int>>> dist(r, vector<vector<int>>(c, vector<int>(2, INT_MAX)));
    vector<vector<vector<bool>>> visited(r, vector<vector<bool>>(c, vector<bool>(2, false)));
    dist[0][0][0] = 0;
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> q;
    q.push({0, 0, 0, 0});
    while (!q.empty())
    {
        auto curr = q.top();
        q.pop();
        int d = curr[0];
        int intmd = curr[1];
        int x = curr[2];
        int y = curr[3];
        //cout << "(" << d << "," << intmd << "," << x << "," << y << ")" << endl;
        if (visited[x][y][intmd])
        {
            continue;
        }
        //go right
        if (y + 1 < c && dist[x][y + 1][0] > d + a[x][y])
        {
            dist[x][y + 1][0] = d + a[x][y];
            q.push({dist[x][y + 1][0], 0, x, y + 1});
        }
        //go left
        if (y > 0 && dist[x][y - 1][0] > d + a[x][y - 1])
        {
            dist[x][y - 1][0] = d + a[x][y - 1];
            q.push({dist[x][y - 1][0], 0, x, y - 1});
        }
        //go down
        if (x + 1 < r && dist[x + 1][y][0] > d + b[x][y])
        {
            dist[x + 1][y][0] = d + b[x][y];
            q.push({dist[x + 1][y][0], 0, x + 1, y});
        }
        //go up
        if (x > 0)
        {
            int cost = 1;
            if (intmd == 0)
            {
                //current node is not intmd, it will take 1 cost
                //to reach an intmd node
                cost++;
            }
            if (dist[x - 1][y][0] > cost + d)
            {
                dist[x - 1][y][0] = cost + d;
                q.push({dist[x - 1][y][0], 1, x - 1, y});
            }
            if (dist[x - 1][y][1] > cost + d)
            {
                dist[x - 1][y][1] = cost + d;
                q.push({dist[x - 1][y][1], 1, x - 1, y});
            }
        }
        visited[x][y][intmd] = true;
    }
    //distance to normal node at cell(r,c);
    cout << dist[r - 1][c - 1][0] << endl;
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