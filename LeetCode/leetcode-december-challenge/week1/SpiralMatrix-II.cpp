#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int A = n;
        vector<vector<int>> result(A, vector<int>(A, 0));
        int curr = 1;
        int i = 0;
        int j = -1;
        int rLimit = A;
        int lLimit = -1;
        int bLimit = A;
        int tLimit = 0;
        bool tR = true;
        bool tL = false;
        bool tB = false;
        bool tT = false;

        while (curr <= (A * A))
        {

            if (tR)
            {
                j++;
                while (j != rLimit)
                {
                    result[i][j] = curr++;
                    j++;
                }
                j--;
                rLimit--;
                tR = false;
                tB = true;
            }
            else if (tL)
            {
                j--;
                while (j != lLimit)
                {
                    result[i][j] = curr++;
                    j--;
                }
                j++;
                lLimit++;
                tL = false;
                tT = true;
            }
            else if (tB)
            {
                i++;
                while (i != bLimit)
                {
                    result[i][j] = curr++;
                    i++;
                }
                i--;
                bLimit--;
                tB = false;
                tL = true;
            }
            else if (tT)
            {
                i--;
                while (i != tLimit)
                {
                    result[i][j] = curr++;
                    i--;
                }
                i++;
                tLimit++;
                tT = false;
                tR = true;
            }
        }
        return result;
    }
};