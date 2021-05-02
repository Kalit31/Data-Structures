#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        int n = A.size();
        int currMax = 0;
        for (int i = 0; i < n - 2; i++)
        {
            currMax = max(currMax, A[i]);
            if (currMax > A[i + 2])
            {
                return false;
            }
        }
        return true;
    }
};