#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int match(string &str, string stamp)
    {
        int n = str.size();
        int m = stamp.size();
        for (int i = 0; i < n; i++)
        {
            int k = i;
            int j = 0;
            bool poss = false;
            while (j < m && k < n && (str[k] == '*' || str[k] == stamp[j]))
            {
                if (str[k] == stamp[j])
                {
                    poss = true;
                }
                k++;
                j++;
            }
            if (j == m && poss)
            {
                for (int ind = i; ind < i + m; ind++)
                {
                    str[ind] = '*';
                }
                return i;
            }
        }
        return n;
    }

    vector<int> movesToStamp(string stamp, string target)
    {
        vector<int> result;
        string toMake = string(target.size(), '*');

        while (target != toMake)
        {
            int ind = match(target, stamp);
            if (ind == target.size())
            {
                return vector<int>();
            }
            result.push_back(ind);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};