#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(int n, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n)
        {
            return false;
        }
        return true;
    }

    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        vector<int> dirX = {1, 0, -1, 0};
        vector<int> dirY = {0, 1, 0, -1};
        int currTime = 0;
        while (true)
        {
            auto curr = pq.top();
            pq.pop();

            if (visited[curr[1]][curr[2]])
            {
                continue;
            }

            currTime = max(currTime, curr[0]);

            if (curr[1] == n - 1 && curr[2] == n - 1)
            {
                return currTime;
            }
            visited[curr[1]][curr[2]] = true;

            for (int i = 0; i < 4; i++)
            {
                int nxtX = curr[1] + dirX[i];
                int nxtY = curr[2] + dirY[i];

                if (!isValid(n, nxtX, nxtY))
                {
                    continue;
                }

                pq.push({grid[nxtX][nxtY], nxtX, nxtY});
            }
        }
        return -1;
    }
};

//Binary Search on answer
class Solution {
public:
    vector<int> dirX = {1,0,-1,0};
    vector<int> dirY = {0,1,0,-1};
    
    bool isValid(int n,int i,int j){
        if(i<0 || j<0 || i>=n || j>=n){
            return false;
        }
        return true;
    }
    
    bool poss(vector<vector<int>>& grid,int t){
        int n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        
        queue<array<int,2>> q;
        q.push({0,0});
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            if(curr[0] == n-1 && curr[1] == n-1){
                return true;
            }
            
            for(int i=0;i<4;i++){
                int nxtX = curr[0]+dirX[i];
                int nxtY = curr[1]+dirY[i];
                if(!isValid(n,nxtX,nxtY) || visited[nxtX][nxtY]){
                    continue;
                }
                if(grid[nxtX][nxtY] > t){
                    continue;
                }
                visited[nxtX][nxtY] = true;
                q.push({nxtX,nxtY});
            }            
        }
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int hi = n*n+1;
        int lo = grid[0][0];
        int ans = hi;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(poss(grid,mid)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return ans;
    }
};
