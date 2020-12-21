#include <bits/stdc++.h>
using namespace std;

// Not working correctly, to debug. Failing for last test case
class Solution
{
public:
    //traverse bottom, left, and bottom-left
    int calcOverlapBottom(vector<vector<int>> &A, vector<vector<int>> &B, int startTop)
    {
        int n = A.size();
        int overlap = 0;
        for (int i = startTop; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] == 1 && B[i - startTop][j] == 1)
                    overlap++;
            }
        }
        return overlap;
    }

    int calcOverlapLeft(vector<vector<int>> &A, vector<vector<int>> &B, int startRight)
    {
        int n = A.size();
        int overlap = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = startRight; j < n; j++)
            {
                if (A[i][j] == 1 && B[i][j - startRight] == 1)
                    overlap++;
            }
        }
        return overlap;
    }

    int calcOverlapBottomLeft(vector<vector<int>> &A, vector<vector<int>> &B, int start)
    {
        int n = A.size();
        int overlap = 0;
        for (int i = start; i < n; i++)
        {
            for (int j = start; j < n; j++)
            {
                if (A[i][j] == 1 && B[i - start][j - start] == 1)
                    overlap++;
            }
        }
        return overlap;
    }

    int largestOverlap(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int n = A.size();
        int maxOverlap = 0;

        //Keep A fixed, traverse B over it, top to bottom
        for (int i = 0; i < n; i++)
        {
            maxOverlap = max(maxOverlap, calcOverlapBottom(A, B, i));
        }
        //cout<<"MAX:"<<maxOverlap<<endl;
        //Keep A fixed, traverse B over it, left to right
        for (int i = 0; i < n; i++)
        {
            maxOverlap = max(maxOverlap, calcOverlapLeft(A, B, i));
        }
        //cout<<"MAX:"<<maxOverlap<<endl;
        //Keep A fixed, traverse B over it, top-left to bottom-right
        for (int i = 0; i < n; i++)
        {
            maxOverlap = max(maxOverlap, calcOverlapBottomLeft(A, B, i));
        }
        //cout<<"MAX:"<<maxOverlap<<endl;
        //Keep B fixed, traverse A over it, top to bottom
        for (int i = 0; i < n; i++)
        {
            maxOverlap = max(maxOverlap, calcOverlapBottom(B, A, i));
        }
        //cout<<"MAX:"<<maxOverlap<<endl;
        //Keep B fixed, traverse A over it, left to right
        for (int i = 0; i < n; i++)
        {
            maxOverlap = max(maxOverlap, calcOverlapLeft(B, A, i));
        }
        //cout<<"MAX:"<<maxOverlap<<endl;
        //Keep B fixed, traverse A over it, top-left to bottom-right
        for (int i = 0; i < n; i++)
        {
            maxOverlap = max(maxOverlap, calcOverlapBottomLeft(B, A, i));
        }
        //cout<<"MAX:"<<maxOverlap<<endl;
        return maxOverlap;
    }
};