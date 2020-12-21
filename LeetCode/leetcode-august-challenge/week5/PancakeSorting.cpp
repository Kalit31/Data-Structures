#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &A)
    {
        vector<int> result;
        int n = A.size();
        if (n == 0)
        {
            return result;
        }
        int curr = n;
        int i = 0;
        while (true)
        {
            i = 0;
            while (A[i] != curr)
            {
                i++;
            }
            if (i + 1 == curr)
            {
                curr--;
                if (curr == 0)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            result.push_back(i + 1);
            reverse(A.begin(), A.begin() + i + 1);
            result.push_back(curr);
            reverse(A.begin(), A.begin() + (curr));
            curr--;
            if (curr == 0)
            {
                break;
            }
        }
        return result;
    }
};

class Solution
{
public:
    vector<int> pancakeSort(vector<int> A)
    {
        vector<int> res;
        int x, i;
        for (x = A.size(); x > 0; --x)
        {
            for (i = 0; A[i] != x; ++i)
                ;
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
            reverse(A.begin(), A.begin() + x);
            res.push_back(x);
        }
        return res;
    }
};