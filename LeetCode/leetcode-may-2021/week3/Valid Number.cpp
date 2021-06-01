#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidNumber(string s)
    {
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int eLoc = s.find('e');

        if (eLoc == std::string::npos)
        {
            return isDecimal(s) || isInteger(s);
        }
        else
        {
            string sub1 = s.substr(0, eLoc);
            string sub2 = s.substr(eLoc + 1);
            return (isDecimal(sub1) || isInteger(sub1)) && isInteger(sub2);
        }
        return true;
    }

    bool isDecimal(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return false;
        }
        bool signPresent = false;
        if (!(s[0] == '+' || s[0] == '-' || s[0] == '.' || isdigit(s[0])))
        {
            return false;
        }
        if (s[0] == '+' || s[0] == '-')
        {
            signPresent = true;
        }
        int dotLoc = s.find('.');
        if (dotLoc == std::string::npos)
        {
            return false;
        }
        if (signPresent)
        {
            int beforeDecimalDigits = dotLoc - 1;
            int afterDecimalDigits = n - dotLoc - 1;

            if (beforeDecimalDigits == 0)
            {
                if (afterDecimalDigits == 0)
                {
                    return false;
                }
                for (int i = dotLoc + 1; i < n; i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return false;
                    }
                }
            }
            else
            {
                for (int i = 1; i < dotLoc; i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return false;
                    }
                }
                for (int i = dotLoc + 1; i < n; i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            int beforeDecimalDigits = dotLoc;
            int afterDecimalDigits = n - dotLoc - 1;

            if (beforeDecimalDigits == 0)
            {
                if (afterDecimalDigits == 0)
                {
                    return false;
                }
                for (int i = dotLoc + 1; i < n; i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return false;
                    }
                }
            }
            else
            {
                for (int i = 0; i < dotLoc; i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return false;
                    }
                }
                for (int i = dotLoc + 1; i < n; i++)
                {
                    if (!isdigit(s[i]))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        return true;
    }

    bool isInteger(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return false;
        }
        bool signPresent = false;
        if (s[0] == '+' || s[0] == '-')
        {
            signPresent = true;
        }
        if (!signPresent)
        {
            if (!isdigit(s[0]))
            {
                return false;
            }
        }

        if (signPresent)
        {
            if (n == 1)
            {
                return false;
            }
            for (int i = 1; i < n; i++)
            {
                if (!isdigit(s[i]))
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (!isdigit(s[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isNumber(string s)
    {
        return isValidNumber(s);
    }
};