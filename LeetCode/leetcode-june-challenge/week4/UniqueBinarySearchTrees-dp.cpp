#include <bits/stdc++.h>
using namespace std;

//Type: Dynamic Programming
//Approach: The basic idea would be to use a bottom up approach, i.e,
//          calculate the combinations for smaller trees and use it
//          to find the combinations for larger trees.
//          For a tree with k nodes, excluding the root, we will have
//          to arrange the nodes between its left and right subtree.

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        if (n < 1)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (dp[i - j] == 0)
                {
                    dp[i] += dp[j - 1];
                }
                else if (dp[j - 1] == 0)
                {
                    dp[i] += dp[i - j];
                }
                else
                {
                    dp[i] += dp[i - j] * dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};