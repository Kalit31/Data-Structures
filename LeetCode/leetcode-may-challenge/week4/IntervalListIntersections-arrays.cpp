#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        int a = A.size();
        int b = B.size();
        int i = 0;
        int j = 0;

        pair<int, int> lastSelected;

        vector<vector<int>> intersections;

        if (a == 0 || b == 0)
        {
            return intersections;
        }

        while (i != a)
        {
            lastSelected = {A[i][0], A[i][1]};
            if (j < 0)
                j = 0;
            while (j != b && B[j][0] <= lastSelected.second)
            {
                if (B[j][0] >= lastSelected.first)
                {
                    if (B[j][1] <= lastSelected.second)
                        intersections.push_back({B[j][0], B[j][1]});
                    else
                        intersections.push_back({B[j][0], lastSelected.second});
                }
                else
                {
                    if (B[j][1] <= lastSelected.second)
                    {
                        if (lastSelected.first <= B[j][1])
                            intersections.push_back({lastSelected.first, B[j][1]});
                    }
                    else
                        intersections.push_back({lastSelected.first, lastSelected.second});
                }
                j++;
            }
            j--;
            i++;
        }
        return intersections;
    }
};

class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A, vector<vector<int>> &B)
    {
        if (A.size() == 0 || B.size() == 0)
            return {};
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < A.size() && j < B.size())
        {
            if (A[i][0] > B[j][1])
            {
                j++;
            }
            else if (A[i][1] < B[j][0])
            {
                i++;
            }
            else
            {
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                if (B[j][1] < A[i][1])
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        return res;
    }
};
