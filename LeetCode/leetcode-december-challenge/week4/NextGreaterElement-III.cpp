#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long long nextNum = stol(s);
        if (nextNum <= n || nextNum > INT_MAX)
        {
            return -1;
        }
        return nextNum;
    }
};

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string digits = to_string(n);

        for (int i = digits.size() - 2; i >= 0; --i)
        {
            if (digits[i] < digits[i + 1])
            {
                for (int j = digits.size() - 1; j > i; --j)
                {
                    if (digits[j] > digits[i])
                    {
                        swap(digits[i], digits[j]);
                        std::reverse(digits.begin() + i + 1, digits.end());
                        long res = stol(digits);
                        return (res > INT_MAX || res <= n) ? -1 : res;
                    }
                }
            }
        }

        return -1;
    }
};