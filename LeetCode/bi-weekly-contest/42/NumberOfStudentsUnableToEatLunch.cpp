#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int n = students.size();
        int sq = 0;
        int cir = 0;
        for (int i = 0; i < n; i++)
        {
            if (students[i] == 1)
            {
                sq++;
            }
            else
            {
                cir++;
            }
        }
        int i = 0;
        while (i < n)
        {
            if (sandwiches[i] == 1)
            {
                if (sq > 0)
                {
                    sq--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (cir > 0)
                {
                    cir--;
                }
                else
                {
                    break;
                }
            }
            i++;
        }
        return n - i;
    }
};