#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findNum(vector<int> &arr, int l, int r)
    {
        int i = l;
        while (i <= r && arr[i] == 0)
        {
            i++;
        }
        vector<int> ans;
        while (i <= r)
        {
            ans.push_back(arr[i]);
            i++;
        }
        return ans;
    }

    vector<int> threeEqualParts(vector<int> &arr)
    {
        int n = arr.size();
        int cntOnes = 0;
        for (int i = 0; i < n; i++)
        {
            cntOnes += arr[i];
        }
        if (cntOnes == 0)
        {
            return {0, n - 1};
        }
        if (cntOnes % 3 != 0)
        {
            return {-1, -1};
        }

        //equal number of ones in every partition = cntOnes/3;
        int req = cntOnes / 3;

        //create the last partition with 'req' ones
        int i = n - 1;
        bool oneOccured = false;
        int zerosBefore = 0;
        while (!oneOccured)
        {
            if (arr[i] == 0)
            {
                zerosBefore++;
            }
            else
            {
                oneOccured = true;
            }
            i--;
        }

        i = 0;
        int cnt = 0;

        while (true)
        {
            cnt += arr[i];
            if (cnt == req)
            {
                break;
            }
            i++;
        }
        int ind1 = i + zerosBefore;
        cnt = 0;
        i = i + zerosBefore + 1;
        while (i < n)
        {
            cnt += arr[i];
            if (cnt == req)
            {
                break;
            }
            i++;
        }
        if (i == n)
        {
            return {-1, -1};
        }
        int ind2 = i + zerosBefore + 1;

        vector<int> a = findNum(arr, 0, ind1);
        vector<int> b = findNum(arr, ind1 + 1, ind2 - 1);
        vector<int> c = findNum(arr, ind2, n - 1);

        if (a == b && b == c)
        {
            return {ind1, ind2};
        }
        return {-1, -1};
    }
};