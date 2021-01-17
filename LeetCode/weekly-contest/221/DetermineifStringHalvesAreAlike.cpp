#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int vowels = 0;
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < (n / 2); i++)
        {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels++;
            }
        }
        for (int i = n / 2; i < n; i++)
        {
            char ch = s[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowels--;
            }
        }
        return vowels == 0;
    }
};