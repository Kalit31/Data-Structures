#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &d)
    {
        string result = "";
        int n = s.size();
        for (int i = 0; i < d.size(); i++)
        {
            string curr = d[i];
            int ptr1 = 0;
            int ptr2 = 0;
            int m = curr.size();

            while (ptr1 < n && ptr2 < m)
            {
                if (s[ptr1] == curr[ptr2])
                {
                    ptr1++;
                    ptr2++;
                }
                else
                {
                    ptr1++;
                }
            }
            if (ptr2 == m)
            {
                if (curr.size() > result.size())
                {
                    result = curr;
                }
                else if (curr.size() == result.size())
                {
                    if (curr.compare(result) < 0)
                        result = curr;
                }
            }
        }

        return result;
    }
};