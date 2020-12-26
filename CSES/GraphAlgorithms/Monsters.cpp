#include <bits/stdc++.h>
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
using namespace std;

// never use endl, it is much slower than "\n"
// dont mess up with LONG_LONG_MAX/LONG_MAX/INT_MAX

// TLE : to fix

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, -1, 0, 1};
const char dir[4] = {'D', 'L', 'U', 'R'};

//MultiSource BFS
void bfsMonster(vector<vector<int>> &grid, vector<array<int, 2>> &monsterPos)
{
    int layerSize = 1;
    int time = 0;
    queue<array<int, 2>> q;
    int n = grid.size();
    int m = grid[0].size();
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < monsterPos.size(); i++)
    {
        q.push({monsterPos[i][0], monsterPos[i][1]});
        visited[monsterPos[i][0]][monsterPos[i][1]] = true;
    }
    while (!q.empty())
    {
        if (layerSize == 0)
        {
            layerSize = q.size();
            time++;
        }
        array<int, 2> curr = q.front();
        q.pop();
        grid[curr[0]][curr[1]] = time;
        for (int i = 0; i < 4; i++)
        {
            int nextI = curr[0] + di[i];
            int nextJ = curr[1] + dj[i];
            if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || grid[nextI][nextJ] == -1)
            {
                continue;
            }
            if (!visited[nextI][nextJ])
            {
                visited[nextI][nextJ] = true;
                q.push({nextI, nextJ});
            }
        }
        layerSize--;
    }
}

//Single Source BFS
void bfsMons(vector<vector<int>> &grid, vector<string> &laby, int i, int j)
{
    grid[i][j] = 0;
    int layerSize = 1;
    int time = 0;
    queue<array<int, 2>> q;
    int n = grid.size();
    int m = grid[0].size();
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    q.push({i, j});
    while (!q.empty())
    {
        if (layerSize == 0)
        {
            layerSize = q.size();
            time++;
        }
        array<int, 2> curr = q.front();
        q.pop();
        grid[curr[0]][curr[1]] = min(grid[curr[0]][curr[1]], time);
        for (int i = 0; i < 4; i++)
        {
            int nextI = curr[0] + di[i];
            int nextJ = curr[1] + dj[i];
            if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || grid[nextI][nextJ] == -1)
            {
                continue;
            }
            if (laby[nextI][nextJ] == 'M')
            {
                continue;
            }
            if (!visited[nextI][nextJ])
            {
                visited[nextI][nextJ] = true;
                q.push({nextI, nextJ});
            }
        }
        layerSize--;
    }
}

void printPath(vector<string> path, int i, int j, int iA, int jA)
{
    cout << "YES" << endl;
    string t;
    while (i != iA || j != jA)
    {
        t += path[i][j];
        //  deb(t);
        if (path[i][j] == 'U')
        {
            i = i + 1;
        }
        else if (path[i][j] == 'D')
        {
            i = i - 1;
        }
        else if (path[i][j] == 'L')
        {
            j = j + 1;
        }
        else if (path[i][j] == 'R')
        {
            j = j - 1;
        }
    }
    reverse(t.begin(), t.end());
    cout << t.size() << endl;
    cout << t << endl;
}

void bfs(vector<vector<int>> &grid, int iA, int jA)
{
    int n = grid.size();
    int m = grid[0].size();
    int layerSize = 1;
    int time = 0;
    vector<string> path(n, string(m, '#'));
    bool visited[n][m];
    memset(visited, false, sizeof(visited));
    queue<array<int, 2>> q;
    q.push({iA, jA});
    while (!q.empty())
    {
        if (layerSize == 0)
        {
            layerSize = q.size();
            time++;
        }
        array<int, 2> curr = q.front();
        q.pop();
        //cout << "POPPING: {" << curr[0] << "," << curr[1] << "}" << endl;

        for (int k = 0; k < 4; k++)
        {
            int nextI = curr[0] + di[k];
            int nextJ = curr[1] + dj[k];
            if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || grid[nextI][nextJ] == -1)
            {
                continue;
            }
            if (grid[nextI][nextJ] > time + 1 && !visited[nextI][nextJ])
            {
                //cout << "PUSHING: {" << nextI << "," << nextJ << "}" << endl;
                q.push({nextI, nextJ});
                visited[nextI][nextJ] = true;
                path[nextI][nextJ] = dir[k];
            }
        }
        layerSize--;
    }

    for (int i = 0; i < n; i++)
    {
        if (path[i][0] != '#')
        {
            printPath(path, i, 0, iA, jA);
            exit(0);
        }
        if (path[i][m - 1] != '#')
        {
            printPath(path, i, m - 1, iA, jA);
            exit(0);
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (path[0][j] != '#')
        {
            printPath(path, 0, j, iA, jA);
            exit(0);
        }
        if (path[n - 1][j] != '#')
        {
            printPath(path, n - 1, j, iA, jA);
            exit(0);
        }
    }
    cout << "NO" << endl;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> grid(n);
    vector<array<int, 2>> monsterPos;
    vector<vector<int>> laby(n, vector<int>(m, -1));
    int aI = -1, aJ = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                aI = i;
                aJ = j;
                laby[i][j] = INT_MAX;
            }
            else if (grid[i][j] == 'M')
            {
                monsterPos.push_back({i, j});
                laby[i][j] = 0;
            }
            else if (grid[i][j] == '.')
            {
                laby[i][j] = INT_MAX;
            }
        }
    }
    if (aI == 0 || aI == n - 1 || aJ == 0 || aJ == m - 1)
    {
        cout << "YES" << endl;
        cout << 0 << endl;
        exit(0);
    }
    bfsMonster(laby, monsterPos);
    /*for (int i = 0; i < monsterPos.size(); i++)
    {
        bfsMons(laby, grid, monsterPos[i][0], monsterPos[i][1]);
    }*/
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (laby[i][j] == -1)
                cout << "# ";
            else
                cout << laby[i][j] << " ";
        }
        cout << endl;
    }*/
    bfs(laby, aI, aJ);
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