#include <bits/stdc++.h>
using namespace std;

//O(N^2)
class Solution
{
public:
    int countPalindrome(string s, int l, int r)
    {
        int cnt = 0;
        int n = s.size();
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                cnt++;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
        return cnt;
    }

    int countSubstrings(string s)
    {
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            cnt += countPalindrome(s, i, i);
            cnt += countPalindrome(s, i, i + 1);
        }
        return cnt;
    }
};

//O(N^3)
class Solution
{
public:
    bool isPalindrome(string s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    int countSubstrings(string s)
    {
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};