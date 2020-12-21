#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i] = digits[i] + carry;
            if (digits[i] > 9)
            {
                carry = digits[i] - 9;
                digits[i] = digits[i] % 10;
            }
            else
            {
                carry = 0;
            }
        }
        if (carry != 0)
        {
            digits.insert(digits.begin(), carry);
        }
        while (digits[0] == 0)
        {
            digits.erase(digits.begin());
        }
        return digits;
    }
};