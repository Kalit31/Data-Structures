#include <bits/stdc++.h>
using namespace std;

//Type: Strings, Math
//Approach: 123
//          132
//      -----------
//          213
//          231
//      -----------
//          312
//          321
//          The thing to observe is that the first digit can be divided into blocks.
//          The size of each block is (n-1)!.
//          So, suppose k = 3, then we can easily find out in which block our number would lie,i.e.,
//          k/(n-1)! = 3/2 = 1st block. Now, we need to update our k = k - block_no*(n-1)!
//          and remove the digit we selected from our set.
//          Additional boundary cases our to be taken care of.
//Complexity: O(N) time

class Solution
{
public:
    void solve(vector<int> &fact, vector<int> &digits, string &result, int n, int k)
    {
        if (n == 1)
        {
            result += to_string(digits.back());
            return;
        }
        int ind = k / fact[n - 1];
        if (k % fact[n - 1] == 0)
        {
            ind--;
        }

        result += to_string(digits[ind]);
        digits.erase(digits.begin() + ind);

        k -= fact[n - 1] * ind;
        solve(fact, digits, result, n - 1, k);
    }

    string getPermutation(int n, int k)
    {
        vector<int> fact(10, 1);
        for (int i = 2; i <= 9; i++)
        {
            fact[i] = fact[i - 1] * i;
        }

        vector<int> digits(n, 0);
        for (int i = 0; i < n; i++)
        {
            digits[i] = i + 1;
        }
        string result = "";
        solve(fact, digits, result, n, k);
        return result;
    }
};