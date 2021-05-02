#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(string s1, string s2)
    {
        int i = 0, j = 0;
        int cnt = 0;
        int n = s1.size();
        while (i < n)
        {
            j = i;
            while (s1[j] != s2[i])
            {
                j++;
            }
            while (i < j)
            {
                char ch = s1[j];
                s1[j] = s1[j - 1];
                s1[j - 1] = ch;
                j--;
                cnt++;
            }
            i++;
        }
        return cnt;
    }

    int getMinSwaps(string num, int k)
    {
        string orig = num;
        next_permutation(num.begin(), num.end());
        do
        {
            k--;
            if (k == 0)
            {
                break;
            }
        } while (next_permutation(num.begin(), num.end()));
        return minSteps(orig, num);
    }
};