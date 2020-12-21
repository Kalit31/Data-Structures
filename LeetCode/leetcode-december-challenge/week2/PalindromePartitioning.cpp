#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string A)
    {
        if (A.length() <= 1)
        {
            return true;
        }
        int n = A.length();
        for (int i = 0; i < (n / 2); i++)
        {
            if (A[i] != A[n - 1 - i])
            {
                return false;
            }
        }
        return true;
    }

    void build(vector<vector<string>> &res, vector<string> &t, string &A, int ind)
    {
        if (A.length() <= ind)
        {
            res.push_back(t);
            return;
        }
        int n = A.length();
        for (int i = 1; i <= (n - ind); i++)
        {
            string sub = A.substr(ind, i);
            if (isPalindrome(sub))
            {
                t.push_back(sub);
                build(res, t, A, ind + i);
                t.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        if (s.size() == 0)
        {
            return result;
        }
        vector<string> t;
        build(result, t, s, 0);
        return result;
    }
};