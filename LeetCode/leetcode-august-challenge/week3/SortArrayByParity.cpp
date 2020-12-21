#include <bits/stdc++.h>
using namespace std;

// O(1) space
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int n = A.size();
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            if (A[start] % 2 == 0)
            {
                start++;
            }
            else
            {
                swap(A[start], A[end]);
                end--;
            }
        }
        return A;
    }
};

//O(N) space
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int n = A.size();
        vector<int> res(n);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (A[i] % 2 == 0)
            {
                res[l] = A[i];
                l++;
            }
            else
            {
                res[r] = A[i];
                r--;
            }
        }
        return res;
    }
};
