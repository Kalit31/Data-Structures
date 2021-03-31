#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> result(n, -1);
        vector<array<int, 2>> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = {B[i], i};
        }

        sort(arr.begin(), arr.end());
        sort(A.begin(), A.end());
        vector<bool> taken(n, false);

        int i = 0;
        int j = 0;

        while (i < n && j < n)
        {
            while (j < n && arr[i][0] >= A[j])
            {
                j++;
            }
            if (j == n)
            {
                break;
            }
            taken[j] = true;
            result[arr[i][1]] = A[j];
            i++;
            j++;
        }
        for (int i = 0; i < n; i++)
        {
            if (result[i] == -1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!taken[j])
                    {
                        taken[j] = true;
                        result[i] = A[j];
                        break;
                    }
                }
            }
        }
        return result;
    }
};