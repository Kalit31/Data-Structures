#include <bits/stdc++.h>
using namespace std;

//Type: Depth First Search
//Approach: The thing to observe here is that,
//          a 'O' on the boundary of matrix along with the cells attached to it and containing 'O'
//          will never get captured. So, while applying a dfs, we can simply change them to a random char
//          and replace them with 'O's at the end. All the other cells would be captured.
//Complexity: O(N*M) time

class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        int n = board.size();
        int m = board[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O')
        {
            return;
        }

        board[i][j] = 'K';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    void solve(vector<vector<char>> &board)
    {
        if (board.size() == 0)
        {
            return;
        }

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }
            if (board[i][m - 1] == 'O')
            {
                dfs(board, i, m - 1);
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
            {
                dfs(board, 0, j);
            }
            if (board[n - 1][j] == 'O')
            {
                dfs(board, n - 1, j);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'K')
                {
                    board[i][j] = 'O';
                }
                else
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};