#include <bits/stdc++.h>
using namespace std;

// O(m*n)
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<array<int, 2>> a(m);
        for (int i = 0; i < m; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                cnt += mat[i][j];
            }
            a[i] = {cnt, i};
        }
        sort(a.begin(), a.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(a[i][1]);
        }
        return ans;
    }
};

//O(m*lgn)
class Solution
{
private:
    int calculateSoldiers(vector<int> &arr)
    {
        int l = 0;
        int h = arr.size() - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (arr[mid] == 0)
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> soldiers;
        for (int i = 0; i < m; i++)
        {
            soldiers.push_back(make_pair(i, calculateSoldiers(mat[i])));
        }
        sort(soldiers.begin(), soldiers.end(), comp());
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(soldiers[i].first);
        }
        return ans;
    }

    struct comp
    {
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            if (a.second > b.second)
                return false;
            else if (a.second == b.second)
                return a.first < b.first;
            return true;
        }
    };
};