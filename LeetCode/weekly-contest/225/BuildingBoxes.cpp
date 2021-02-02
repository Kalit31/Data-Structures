#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(int n)
    {
        int dia_sz = 0, last_dia = 0;
        while (n - (dia_sz + 1) * (dia_sz + 2) / 2 > 0)
        {
            ++dia_sz;
            n -= dia_sz * (dia_sz + 1) / 2;
        }
        while (n > 0)
            n -= ++last_dia;
        return dia_sz * (dia_sz + 1) / 2 + last_dia;
    }
};