#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        int i = 0;
        int j = m - 1;
        while (i < n && j >= 0)
        {
            if (a[i] != b[j])
            {
                return false;
            }
            i++;
            j--;
        }
        if (j == -1)
        {
            //string b completely utilized
            if (i != n)
            {
                j = n - 1;
                while (i < j)
                {
                    if (a[i] != a[j])
                    {
                        return false;
                    }
                    i++;
                    j--;
                }
            }
        }
        else
        {
            i = 0;
            while (i < j)
            {
                if (b[i] != b[j])
                {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> result;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (check(words[i], words[j]))
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};