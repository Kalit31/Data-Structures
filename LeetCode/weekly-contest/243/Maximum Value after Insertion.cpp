#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maxValue(string n, int x)
    {
        string result = "";
        if (n[0] == '-')
        {
            result += '-';
            bool taken = false;
            for (int i = 1; i < n.size(); i++)
            {
                if ((n[i] - '0') > x)
                {
                    if (taken)
                    {
                        result += n[i];
                    }
                    else
                    {
                        result += to_string(x) + n[i];
                        taken = true;
                    }
                }
                else
                {
                    result += n[i];
                }
            }
            if (!taken)
            {
                result += to_string(x);
            }
        }
        else
        {
            //num is +ve
            bool taken = false;
            for (int i = 0; i < n.size(); i++)
            {
                if ((n[i] - '0') < x)
                {
                    if (taken)
                    {
                        result += n[i];
                    }
                    else
                    {
                        result += to_string(x) + n[i];
                        taken = true;
                    }
                }
                else
                {
                    result += n[i];
                }
            }
            if (!taken)
            {
                result += to_string(x);
            }
        }
        return result;
    }
};