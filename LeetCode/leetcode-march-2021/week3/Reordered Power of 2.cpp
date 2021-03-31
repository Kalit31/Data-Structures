#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> computeDigitFreq(int n)
    {
        vector<int> freq(10, 0);
        while (n)
        {
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    }

    bool reorderedPowerOf2(int N)
    {
        vector<int> numFreq = computeDigitFreq(N);
        for (int i = 0; i < 31; i++)
        {
            if (numFreq == computeDigitFreq(1 << i))
            {
                return true;
            }
        }
        return false;
    }
};

//Brute Force Soln
class Solution
{
public:
    bool isPowerTwo(int n)
    {
        while (n % 2 == 0)
        {
            n /= 2;
        }
        return n == 1;
    }

    bool reorderedPowerOf2(int N)
    {
        vector<int> digits;
        int tN = N;
        while (tN)
        {
            digits.push_back(tN % 10);
            tN /= 10;
        }
        sort(digits.begin(), digits.end());
        do
        {
            if (digits[0] == 0)
                continue;
            int num = 0;
            int curr = 1;
            for (int i = digits.size() - 1; i >= 0; i--)
            {
                num += curr * digits[i];
                curr *= 10;
            }
            if (isPowerTwo(num))
                return true;
        } while (next_permutation(digits.begin(), digits.end()));
        return false;
    }
};
