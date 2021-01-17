#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countVowelStrings(int n)
    {
        vector<int> freq = {1, 1, 1, 1, 1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 3; j >= 0; j--)
            {
                freq[j] = freq[j] + freq[j + 1];
            }
        }
        return freq[0];
    }
};

class Solution
{
public:
    //Pentatope number
    int countVowelStrings(int n)
    {
        n++;
        return ((n) * (n + 1) * (n + 2) * (n + 3)) / 24;
    }
};