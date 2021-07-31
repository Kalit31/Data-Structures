#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;

        for (int j = 0; j < n; j++)
        {
            pq.push({matrix[0][j], 0, j});
        }
        k--;
        while (k--)
        {
            auto curr = pq.top();
            pq.pop();
            if (curr[1] == n - 1)
            {
                continue;
            }
            pq.push({matrix[curr[1] + 1][curr[2]], curr[1] + 1, curr[2]});
        }
        return pq.top()[0];
    }
};

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }
};