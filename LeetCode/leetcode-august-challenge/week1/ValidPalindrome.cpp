#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.length();
        while (l < r)
        {
            while (l < r && !isalnum(s[l]))
                l++;
            while (l < r && !isalnum(s[r]))
                r--;
            char c1 = tolower(s[l]);
            char c2 = tolower(s[r]);
            if (c1 != c2)
                return false;
            l++;
            r--;
        }
        return true;
    }
};

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string newString = "";
        for (char ch : s)
        {
            if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            {
                newString += ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                newString += (ch + 32);
            }
        }
        int n = newString.length();
        for (int i = 0; i < (n / 2); i++)
        {
            if (newString[i] != newString[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
