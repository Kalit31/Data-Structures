#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& time, int i, int j, int t) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int n = grid.size();
        int m = grid[0].size();

        if (i<0 || j<0 || i>=n || j>=m) {
            return;
        }

        if (grid[i][j]==1) {
            //cout<<"I:"<<i<<"J:"<<j<<endl;
            time[i][j] = min(time[i][j], t+1);
            grid[i][j] = 0;
            bfs(grid, time, i+1, j, t+1);
            bfs(grid, time, i-1, j, t+1);
            bfs(grid, time, i, j+1, t+1);
            bfs(grid, time, i, j-1, t+1);
            grid[i][j] = 1;
        }
    }


    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (grid[i][j]==2) {
                    time[i][j] = 0;
                    bfs(grid, time, i+1, j, 0);
                    bfs(grid, time, i-1, j, 0);
                    bfs(grid, time, i, j+1, 0);
                    bfs(grid, time, i, j-1, 0);
                }
                else if (grid[i][j]==0) {
                    time[i][j] = 0;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<time[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int maxTime = INT_MIN;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (time[i][j]==INT_MAX) {
                    return -1;
                }
                maxTime = max(maxTime, time[i][j]);
            }
        }
        return maxTime==INT_MIN ? 0 : maxTime;
    }
};