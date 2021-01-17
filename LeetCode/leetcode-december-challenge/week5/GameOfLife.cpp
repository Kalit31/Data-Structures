#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
    int dy[8] = {0, -1, 0, 1, -1, -1, 1, 1};
    int m, n;

    int countNeighbours(vector<vector<int>> &board, int i, int j)
    {
        int count = 0;
        for (int k = 0; k < 8; k++)
        {
            int nextI = i + dx[k];
            int nextJ = j + dy[k];
            if (nextI < 0 || nextJ < 0 || nextI >= m || nextJ >= n)
            {
                continue;
            }
            count += board[nextI][nextJ] == 1 ? 1 : 0;
        }
        return count;
    }

    void gameOfLife(vector<vector<int>> &board)
    {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 0)
                {
                    if (countNeighbours(board, i, j) == 3)
                    {
                        ans[i][j] = 1;
                    }
                }
                else
                {
                    int count = countNeighbours(board, i, j);
                    if (count < 2)
                    {
                        ans[i][j] = 0;
                    }
                    else if (count == 2 || count == 3)
                    {
                        ans[i][j] = 1;
                    }
                    else
                    {
                        ans[i][j] = 0;
                    }
                }
            }
        }
        board = ans;
    }
};

//Inplace solution
class Solution
{
public:
    bool exists(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n) && (j >= 0 && j < m);
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x == i && y == j)
                            continue;
                        if (exists(x, y, n, m))
                        {
                            sum += board[x][y] % 2;
                        }
                    }
                }
                if (board[i][j] == 0 && sum == 3)
                {
                    board[i][j] = 2;
                }
                else if (board[i][j] == 1 && (sum < 2 || sum > 3))
                {
                    board[i][j] = 3;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] > 1)
                {
                    board[i][j] = (board[i][j] - 1) % 2;
                }
            }
        }
    }
};