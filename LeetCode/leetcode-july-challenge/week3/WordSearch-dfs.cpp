#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(vector<vector<char>> &board, string word, int curr, int i, int j)
    {
        if (curr == word.length())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[curr])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = ' ';
        bool found = dfs(board, word, curr + 1, i + 1, j) ||
                     dfs(board, word, curr + 1, i - 1, j) ||
                     dfs(board, word, curr + 1, i, j + 1) ||
                     dfs(board, word, curr + 1, i, j - 1);
        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (dfs(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};