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

vector<int> dirX = {1, 0, -1, 0};
vector<int> dirY = {0, 1, 0, -1};

vector<vector<char>> currBoard;
set<vector<vector<char>>> boardsVisited;

int n, k;
int ans;

void dfs(int left)
{
    if (boardsVisited.find(currBoard) != boardsVisited.end())
    {
        return;
    }
    boardsVisited.insert(currBoard);

    if (left == 0)
    {
        ans++;
        return;
    }

    vector<array<int, 2>> validLocs;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (currBoard[i][j] == '.')
            {
                bool ok = false;
                for (int d = 0; d < 4; d++)
                {
                    int nxtX = i + dirX[d];
                    int nxtY = j + dirY[d];
                    if (nxtX < 0 || nxtY < 0 || nxtX >= n || nxtY >= n || currBoard[nxtX][nxtY] == '#' || currBoard[nxtX][nxtY] == '.')
                    {
                        continue;
                    }
                    ok = true;
                    break;
                }
                if (ok)
                {
                    validLocs.push_back({i, j});
                }
            }
        }
    }
    for (int i = 0; i < validLocs.size(); i++)
    {
        currBoard[validLocs[i][0]][validLocs[i][1]] = '@';
        dfs(left - 1);
        currBoard[validLocs[i][0]][validLocs[i][1]] = '.';
    }
}

void solve()
{
    cin >> n >> k;
    currBoard.resize(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> currBoard[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (currBoard[i][j] == '.')
            {
                currBoard[i][j] = '@';
                dfs(k - 1);
                currBoard[i][j] = '.';
            }
        }
    }

    cout << ans << endl;
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