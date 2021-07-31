#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size();
        string result(n, '.');

        int last = 0;
        int i = 0;

        while (i < n && dominoes[i] == '.')
        {
            i++;
        }

        if (dominoes[i] == 'L')
        {
            while (last != i)
            {
                result[last] = 'L';
                last++;
            }
        }
        last = i;
        result[last] = dominoes[last];
        i++;

        while (i < n)
        {
            if (dominoes[i] == '.')
            {
                i++;
            }
            else
            {
                if (dominoes[last] == 'L' && dominoes[i] == 'L')
                {

                    while (last <= i)
                    {
                        result[last] = 'L';
                        last++;
                    }
                    last = i;
                }
                else if (dominoes[last] == 'R' && dominoes[i] == 'L')
                {
                    int ind1 = last;
                    int ind2 = i;
                    while (ind1 < ind2)
                    {
                        result[ind1] = 'R';
                        result[ind2] = 'L';
                        ind1++;
                        ind2--;
                    }
                    last = i;
                }
                else if (dominoes[last] == 'L' && dominoes[i] == 'R')
                {
                    last = i;
                }
                else
                {
                    while (last <= i)
                    {
                        result[last] = 'R';
                        last++;
                    }
                    last = i;
                }
                i++;
            }
        }

        if (dominoes[last] == 'R')
        {
            while (last != i)
            {
                result[last] = 'R';
                last++;
            }
        }

        return result;
    }
};