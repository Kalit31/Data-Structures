#include <bits/stdc++.h>
using namespace std;

//Type: DFS

//Approach: A typical DFS traversal. For each 1 you encounter while traversing the grid.
//          Apply a dfs from that cell and increment the island count.
//          The DFS would make all the adjacent reachable 1's as 0's,
//          so that they do not get counted multiple times.
//Complexity: O(N*N) time

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                    numIslands += dfs(grid, i, j);
            }
        }
        return numIslands;
    }

    int dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        {
            return 0;
        }

        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);

        return 1;
    }
};