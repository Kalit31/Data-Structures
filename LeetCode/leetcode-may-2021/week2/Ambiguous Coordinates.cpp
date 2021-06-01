#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() == 1)
        {
            return true;
        }
        bool decimalPresent = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '.')
            {
                decimalPresent = true;
                break;
            }
        }
        if (!decimalPresent)
        {
            bool allZeros = true;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != '0')
                {
                    allZeros = false;
                    break;
                }
            }
            if (allZeros)
                return false;
            return s[0] != '0';
        }
        else
        {
            bool firstZero = s[0] == '0';
            if (!firstZero)
            {
                return s[s.size() - 1] != '0';
            }
            else
            {
                return (s[1] == '.' && s[s.size() - 1] != '0');
            }
        }
        return false;
    }

    vector<string> validNumbers(string s)
    {
        vector<string> result;

        if (isValid(s))
            result.push_back(s);

        for (int i = 1; i < s.size(); i++)
        {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            string curr = s1 + "." + s2;
            if (isValid(curr))
                result.push_back(curr);
        }

        return result;
    }

    vector<string> ambiguousCoordinates(string s)
    {
        s = s.substr(1, s.size() - 2);
        vector<string> result;
        for (int i = 1; i < s.size(); i++)
        {
            string s1 = s.substr(0, i);
            string s2 = s.substr(i);
            vector<string> nums1 = validNumbers(s1);
            vector<string> nums2 = validNumbers(s2);
            for (string str1 : nums1)
            {
                for (string str2 : nums2)
                {
                    string curr = "(" + str1 + ", " + str2 + ")";
                    result.push_back(curr);
                }
            }
        }
        return result;
    }
};