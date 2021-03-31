#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reinitializePermutation(int n)
    {
        vector<int> initial(n);
        for (int i = 0; i < n; i++)
        {
            initial[i] = i;
        }
        vector<int> curr = initial;
        int moves = 0;
        while (true)
        {
            vector<int> arr(n);
            for (int i = 0; i < n; i += 2)
            {
                arr[i] = curr[i / 2];
            }
            for (int i = 1; i < n; i += 2)
            {
                arr[i] = curr[n / 2 + (i - 1) / 2];
            }
            curr = arr;
            moves++;
            if (curr == initial)
            {
                return moves;
            }
        }
        return moves;
    }
};