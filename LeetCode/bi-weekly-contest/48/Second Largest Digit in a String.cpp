#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondHighest(string s)
    {
        vector<int> digits;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] - '0' >= 0 && s[i] - '0' <= 9)
            {
                digits.push_back(s[i] - '0');
            }
        }
        if (digits.size() <= 1)
            return -1;
        sort(digits.begin(), digits.end(), greater<int>());
        int first = digits[0];
        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] != first)
            {
                return digits[i];
            }
        }
        return -1;
    }
};