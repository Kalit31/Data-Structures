#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0;
        int curr = 1;
        while (i < n)
        {
            while (arr[i] != curr)
            {
                k--;
                if (k == 0)
                {
                    return curr;
                }
                curr++;
            }
            i++;
            curr++;
        }
        if (i == n && k != 0)
        {
            return (curr + k - 1);
        }
        return -1;
    }
};