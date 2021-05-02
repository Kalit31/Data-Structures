#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int currBrickSum = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (heights[i + 1] < heights[i])
            {
                continue;
            }
            else
            {
                //use either bricks or ladder
                int diff = heights[i + 1] - heights[i];
                minHeap.push(diff);
                if (minHeap.size() > ladders)
                {
                    int num = minHeap.top();
                    minHeap.pop();
                    if (currBrickSum + num > bricks)
                    {
                        return i;
                    }
                    else
                    {
                        currBrickSum += num;
                    }
                }
            }
        }
        return n - 1;
    }
};