#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        int pos = 0;
        int temp = 0;
        int len = max(a.size(), b.size());
        int less = len - min(a.size(), b.size());
        for (int i = len - 1; i >= 0; i--)
        {
            if (len - i > len - less)
            {
                break;
            }
            temp = pos + (a.size() > b.size() ? a[i] - '0' + b[i - less] - '0' : a[i - less] - '0' + b[i] - '0');
            ans.insert(ans.begin(), temp % 2 + '0');
            pos = temp / 2;
        }
        for (int i = less - 1; i >= 0; i--)
        {
            temp = pos + (a.size() > b.size() ? a[i] - '0' : b[i] - '0');
            ans.insert(ans.begin(), temp % 2 + '0');
            pos = temp / 2;
        }
        if (pos)
        {
            ans.insert(ans.begin(), '1');
        }
        return ans;
    }
};

class Solution
{
public:
    string addBinary(string a, string b)
    {
        if (b.length() > a.length())
        {
            string t = a;
            a = b;
            b = t;
        }
        int l1 = a.length();
        int l2 = b.length();

        int carry = 0;
        string res = "";
        int i;
        int j;
        for (i = l1 - 1, j = l2 - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (a[i] == '0' && b[j] == '0')
            {
                res = to_string(carry) + res;
                carry = 0;
            }
            else if (a[i] == '1' && b[j] == '1')
            {
                res = to_string(carry) + res;
                carry = 1;
            }
            else
            {
                if (carry)
                {
                    res = '0' + res;
                }
                else
                {
                    res = '1' + res;
                }
            }
        }
        while (i >= 0)
        {
            if (carry)
            {
                if (a[i] == '1')
                {
                    res = '0' + res;
                }
                else
                {
                    res = '1' + res;
                    carry = 0;
                }
            }
            else
            {
                res = a[i] + res;
            }
            i--;
        }
        if (carry)
        {
            res = '1' + res;
        }
        return res;
    }
};